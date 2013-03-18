// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// Util
//		Game-wide utilities.

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Util.h"
#include <Windows.h>

// |----------------------------------------------------------------------------|
// |								 Globals									|
// |----------------------------------------------------------------------------|
int SCREEN_WIDTH;
int SCREEN_HEIGHT;
float SCALE_X;
float SCALE_Y;

void debug(const char* msg, int level) 
{ 
	if (level <= DEBUG_MODE)
	{
		OutputDebugStringA(msg);
		OutputDebugStringA("\n");
	}
}