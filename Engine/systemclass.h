// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// SystemClass
//		Contains management classes for game objects, sound, graphics, and input.
#pragma once


// |----------------------------------------------------------------------------|
// |						Pre-Processing Directives							|
// |----------------------------------------------------------------------------|
#define WIN32_LEAN_AND_MEAN


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include <windows.h>
#include "inputclass.h"
#include "graphicsclass.h"
#include "timerclass.h"
#include "soundclass.h"
#include "game.h"


// |----------------------------------------------------------------------------|
// |							Class: SystemClass								|
// |----------------------------------------------------------------------------|
class SystemClass
{
public:

	//|-------------------------------Public Functions--------------------------|

	// Constructors and Destructors
	SystemClass();
	SystemClass(const SystemClass&);
	~SystemClass();

	// Initialize all data members
	bool Initialize();

	// Release all data members
	void Shutdown();

	// Run the game (contains main game loop)
	void Run();

	// Handles system messages
	LRESULT CALLBACK MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);

private:

	//|-------------------------------Private Functions-------------------------|

	// Processes each frame (calles input, game, render frame functions)
	bool Frame();

	// Performs Windows initialization tasks
	void InitializeWindows(int& screenWidth, int& screenHeight);

	// Performs Windows shutdown tasks
	void ShutdownWindows();

private:

	// Windows parameters
	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	// Input handler
	InputClass* m_Input;

	// Graphics handler
	GraphicsClass* m_Graphics;	

	// Game logic handler
	Game* m_game;
	
	// Timing classes
	TimerClass* m_Timer;

	// Sound
	SoundClass* m_Sound;
};


// |----------------------------------------------------------------------------|
// |								 Globals									|
// |----------------------------------------------------------------------------|
static SystemClass* ApplicationHandle = 0;


// |----------------------------------------------------------------------------|
// |							Function Prototypes								|
// |----------------------------------------------------------------------------|
static LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam);

