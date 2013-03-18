// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// TimerClass
//		Controls counter for general timer


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "timerclass.h"


// |----------------------------------------------------------------------------|
// |						   Default Constructor								|
// |----------------------------------------------------------------------------|
TimerClass::TimerClass()
{
}


// |----------------------------------------------------------------------------|
// |						    Copy Constructor								|
// |----------------------------------------------------------------------------|
TimerClass::TimerClass(const TimerClass& other)
{
}


// |----------------------------------------------------------------------------|
// |						     Deconstructor									|
// |----------------------------------------------------------------------------|
TimerClass::~TimerClass()
{
}


// |----------------------------------------------------------------------------|
// |						      Initialize									|
// |----------------------------------------------------------------------------|
bool TimerClass::Initialize()
{
	// Check to see if this system supports high performance timers.
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_frequency);
	if(m_frequency == 0)
	{
		return false;
	}

	// Find out how many times the frequency counter ticks every millisecond.
	m_ticksPerMs = (float)(m_frequency / 1000);

	QueryPerformanceCounter((LARGE_INTEGER*)&m_startTime);

	return true;
}


// |----------------------------------------------------------------------------|
// |						        Frame										|
// |----------------------------------------------------------------------------|
void TimerClass::Frame()
{
	INT64 currentTime;
	float timeDifference;


	QueryPerformanceCounter((LARGE_INTEGER*)& currentTime);

	timeDifference = (float)(currentTime - m_startTime);

	m_frameTime = timeDifference / m_ticksPerMs;

	m_startTime = currentTime;

	return;
}


// |----------------------------------------------------------------------------|
// |								 GetTime									|
// |----------------------------------------------------------------------------|
float TimerClass::GetTime()
{
	return m_frameTime;
}