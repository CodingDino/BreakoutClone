// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// GraphicsClass
//		Overall control of graphics and rendering, holds model objects and other graphics objects
#pragma once


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "d3dclass.h"
#include "textureshaderclass.h"
#include "Coord.h"
#include "Util.h"
#include "BitmapClass.h"
#include "cameraclass.h"


// |----------------------------------------------------------------------------|
// |								 Globals									|
// |----------------------------------------------------------------------------|
const bool FULL_SCREEN = true;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;
const int NUM_MODELS=20;


// |----------------------------------------------------------------------------|
// |					       Class: GraphicsClass								|
// |----------------------------------------------------------------------------|
class GraphicsClass
{
public:

	//|-------------------------------Public Functions--------------------------|

	// Singleton instance requests
	static GraphicsClass* GetInstance();
	
    // Initialization and shutdown
	bool Initialize(int screenWidth, int screenHeight, HWND hwnd);
	void Shutdown();

	// Frame-by-frame graphics processing
	bool Frame();

	// Calls render functions in order
	bool Render();

	// Rendering setup (starts scene, gets world, view, and projection matrix)
	bool BeginRender();

	// Rendering cleanup (ends the scene)
	bool EndRender();

	// Renders the passed in bitmap using the given transforms
	bool BitmapRender(BitmapClass& to_render, int x, int y);

private:

	//|-------------------------------Private Functions-------------------------|

	// Constructors and Destructors
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

private:

	//|-----------------------------Private Data Members------------------------|

	// Instance of the singleton
	static GraphicsClass* s_instance;

	// DirectX object
	D3DClass* m_D3D;

	// Camera
	CameraClass* m_camera;

	// Shaders
	TextureShaderClass* m_textureShader;

	// 2D Bitmaps
	BitmapClass* m_titleScreen;

	// Text Objects
	//TextClass* m_text;

	// Screen dimmensions
	int m_screenWidth;
	int m_screenHeight;

	// Matrices
	D3DXMATRIX worldMatrix, viewMatrix, projectionMatrix, orthoMatrix, baseViewMatrix;

};