// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// Util
//		Game-wide utilities.
#pragma once


// |----------------------------------------------------------------------------|
// |								Constants									|
// |----------------------------------------------------------------------------|
const int DEBUG_MODE = 0;
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern float SCALE_X;
extern float SCALE_Y;


// |----------------------------------------------------------------------------|
// |							Function Prototypes								|
// |----------------------------------------------------------------------------|
void debug(const char* msg, int level=1);