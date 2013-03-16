// Solar Exploration Sim
// Developed for DirectX Coursework for Abertay University, based on tutorials from http://www.rastertek.com
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Util
//		Game-wide utilities.
#pragma once


// |----------------------------------------------------------------------------|
// |								Constants									|
// |----------------------------------------------------------------------------|
const int DEBUG_MODE = 1;
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern float SCALE_X;
extern float SCALE_Y;


// |----------------------------------------------------------------------------|
// |							Function Prototypes								|
// |----------------------------------------------------------------------------|
void debug(const char* msg, int level=1);