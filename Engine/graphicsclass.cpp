// Solar Exploration Sim
// Developed for DirectX Coursework for Abertay University, based on tutorials from http://www.rastertek.com
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// GraphicsClass
//		Overall control of graphics and rendering, holds model objects and other graphics objects


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "graphicsclass.h"
#include <cmath>

// |----------------------------------------------------------------------------|
// |						       GetInstance									|
// |----------------------------------------------------------------------------|
GraphicsClass* GraphicsClass::s_instance=0;
GraphicsClass* GraphicsClass::GetInstance()
{
	if (!s_instance)
	{
		s_instance = new GraphicsClass();
	}
	return s_instance;
}


// |----------------------------------------------------------------------------|
// |						   Default Constructor								|
// |----------------------------------------------------------------------------|
GraphicsClass::GraphicsClass() :
	m_D3D(0),
	m_textureShader(0),
	m_camera(0),
	m_titleScreen(0)
{
}

	
// |----------------------------------------------------------------------------|
// |						    Copy Constructor								|
// |----------------------------------------------------------------------------|
GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


// |----------------------------------------------------------------------------|
// |						     Deconstructor									|
// |----------------------------------------------------------------------------|
GraphicsClass::~GraphicsClass()
{
}


// |----------------------------------------------------------------------------|
// |						      Initialize									|
// |----------------------------------------------------------------------------|
bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	// Record screen dimmensions
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	// Create the Direct3D object.
	m_D3D = D3DClass::GetInstance();
	if(!m_D3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	m_camera = new CameraClass;
	if(!m_camera)
	{
		return false;
	}

	// Initialize a base view matrix with the camera for 2D user interface rendering.
	m_camera->SetPosition(0.0f, 0.0f, -1.0f);
	m_camera->Render();
	m_camera->GetViewMatrix(baseViewMatrix);

	// Create the shader objects.
	m_textureShader = new TextureShaderClass;
	if(!m_textureShader)
	{
		return false;
	}
	

	// Initialize the shader object.
	result = m_textureShader->Initialize(m_D3D->GetDevice(), hwnd);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the texture shader object.", L"Error", MB_OK);
		return false;
	}

	// Create the bitmap objects.
	m_titleScreen = new BitmapClass;
	if(!m_titleScreen)
	{
		return false;
	}

	// Turn off the Z buffer and turn on alpha blending.
	m_D3D->TurnZBufferOff();
	m_D3D->TurnOnAlphaBlending();

	return true;
}


// |----------------------------------------------------------------------------|
// |						      Shutdown										|
// |----------------------------------------------------------------------------|
void GraphicsClass::Shutdown()
{

	// Release the text object.
	//if(m_Text)
	//{
	//	m_Text->Shutdown();
	//	delete m_Text;
	//	m_Text = 0;
	//}

	// Release the camera object.
	if(m_camera)
	{
		delete m_camera;
		m_camera = 0;
	}

	// Release the bitmap objects.
	if(m_titleScreen)
	{
		m_titleScreen->Shutdown();
		delete m_titleScreen;
		m_titleScreen = 0;
	}

	// Release the shader objects.
	if(m_textureShader)
	{
		m_textureShader->Shutdown();
		delete m_textureShader;
		m_textureShader = 0;
	}

	// Release the D3D object.
	if(m_D3D)
	{
		m_D3D->Shutdown();
		m_D3D = 0;
	}
	
	delete s_instance;
	s_instance = 0;

	return;
}


// |----------------------------------------------------------------------------|
// |						       Frame										|
// |----------------------------------------------------------------------------|
bool GraphicsClass::Frame()
{
	bool result;

	// Render the graphics scene.
	result = Render();
	if(!result)
	{
		return false;
	}

	return true;
}


// |----------------------------------------------------------------------------|
// |						      Render										|
// |----------------------------------------------------------------------------|
bool GraphicsClass::Render()
{
	bool result;
	static float rotation = 0.0f;

	result = BeginRender();

	// BITMAP rendering
	// Determine correct titlescreen location
	int xCoord = (m_screenWidth-min(m_screenWidth,1024*m_screenHeight/768))/2;
	result = result && BitmapRender(*m_titleScreen, xCoord, 0);

	// TEXT rendering
	//result = m_Text->Render(m_D3D->GetDeviceContext(), worldMatrix, orthoMatrix);
	//if(!result)
	//{
	//	return false;
	//}

	// Perform closing actions
	result = result && EndRender();

	return result;
}


// |----------------------------------------------------------------------------|
// |						    BeginRender										|
// |----------------------------------------------------------------------------|
bool GraphicsClass::BeginRender()
{
	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_D3D->GetWorldMatrix(worldMatrix);
	m_D3D->GetProjectionMatrix(projectionMatrix);
	m_D3D->GetOrthoMatrix(orthoMatrix);

	return true;
}


// |----------------------------------------------------------------------------|
// |						    EndRender										|
// |----------------------------------------------------------------------------|
bool GraphicsClass::EndRender()
{
	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}


// |----------------------------------------------------------------------------|
// |						    BitmapRender									|
// |----------------------------------------------------------------------------|
bool GraphicsClass::BitmapRender(BitmapClass& to_render, int x, int y)
{
	//debug ("GraphicsClass: Rendering Bitmap");

	bool result;

	// Change world matrix to identity before rendering.
	D3DXMatrixIdentity(&worldMatrix);
	
	// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.
	result = to_render.Render(m_D3D->GetDeviceContext(), x, y);
	if(!result)
	{
		debug ("GraphicsClass: Problem with bitmap.Render()");
		return false;
	}
	// Render the bitmap with the texture shader.
	result = m_textureShader->Render(m_D3D->GetDeviceContext(), to_render.GetIndexCount(), 
		worldMatrix, baseViewMatrix, orthoMatrix, to_render.GetTexture());
	if(!result)
	{
		debug ("GraphicsClass: Problem with shader.Render()");
		return false;
	}

	return result;
}