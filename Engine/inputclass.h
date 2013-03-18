// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// InputClass
//		Gets and processes input to be made available for game class to use in 
//		game logic.
#pragma once


// |----------------------------------------------------------------------------|
// |						Pre-Processing Directives							|
// |----------------------------------------------------------------------------|
#define DIRECTINPUT_VERSION 0x0800


// |----------------------------------------------------------------------------|
// |								 Linking									|
// |----------------------------------------------------------------------------|
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include <dinput.h>


// |----------------------------------------------------------------------------|
// |						   Class: InputClass								|
// |----------------------------------------------------------------------------|
class InputClass
{
public:

	//|-------------------------------Public Functions--------------------------|

	// Singleton instance requests
	static InputClass* GetInstance();
	
    // Initialization and shutdown
	bool Initialize(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight);
	void Shutdown();
	
	// Gets input and processes it
	bool Frame();

	// Key press checks
	bool IsEscapePressed();

	// Gets mouse position
	void GetMouseLocation(int& mouseX, int& mouseY);
	bool IsMouseButtonDown(int button) {if (button >= 0 && button < 4) return m_mouseDown; else return false;}
	bool IsMouseButtonPressed(int button) {if (button >= 0 && button < 4) return m_mousePressed; else return false;}

private:

	//|-------------------------------Private Functions-------------------------|

	// Constructors and Destructors
	InputClass();
	InputClass(const InputClass&);
	~InputClass();

	// Read the current state of the keyboard
	bool ReadKeyboard();

	// Read the current state of the mouse
	bool ReadMouse();

	// Process the changes in the mouse and keyboard
	void ProcessInput();

private:

	//|-----------------------------Private Data Members------------------------|

	// Instance of the singleton
	static InputClass* s_instance;

	// Pointers to mouse, keyboard, input
	IDirectInput8* m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;

	// States for mouse and keyboard
	unsigned char m_keyboardState[256];
	DIMOUSESTATE m_mouseState;

	// screen dimensions for use with mouse
	int m_screenWidth, m_screenHeight;

	// mouse coordinates
	int m_mouseX, m_mouseY;
	bool m_mouseDown, m_mousePressed;
};