// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// TimerClass
//		Controls counter for general timer
#pragma once


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include <windows.h>


// |----------------------------------------------------------------------------|
// |						     Class: TimerClass								|
// |----------------------------------------------------------------------------|
class TimerClass
{
public:

	//|-------------------------------Public Functions--------------------------|
	
	// Constructors and Destructors
	TimerClass();
	TimerClass(const TimerClass&);
	~TimerClass();
	
	// Initiallizes the object
	bool Initialize();

	// Called once each frame render
	void Frame();
	
	// Getter functions
	float GetTime();

private:

	//|-----------------------------Private Data Members------------------------|
	INT64 m_frequency;
	float m_ticksPerMs;
	INT64 m_startTime;
	float m_frameTime;
};