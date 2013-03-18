// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// Button
//		Defines the screen change button's location, text, image, and function. 


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Button.h"


// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Button::Button() :
    m_parent(NULL),
    m_nextScreen(QUIT)
{
	debug ("Button: object instantiated.");
}


// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Button::~Button() {
	debug ("Button: instance destroyed.");
}
   

// |----------------------------------------------------------------------------|
// |							  Copy Constructor								|
// |----------------------------------------------------------------------------|
Button::Button(const Button&) {
	debug ("Button: object copied.");
}


// |----------------------------------------------------------------------------|
// |							   Initialize									|
// |----------------------------------------------------------------------------|
bool Button::Initialize(Screen* parent, SCREEN nextScreen, WCHAR* textureFilename) {

	// Record parent
	m_parent = parent;

	// Set dimmensions
	m_dimmensions.x = 178*SCALE_X;
	m_dimmensions.y = 76*SCALE_Y;

	// Set click to screen
	m_nextScreen = nextScreen;
	
	// Loading graphics into Image objects
	m_graphic = new BitmapClass();
	m_graphic->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, textureFilename, (int)m_dimmensions.x, (int)m_dimmensions.y);
	
	debug ("Button: object initialized.");

	return true;
}


// |----------------------------------------------------------------------------|
// |							    Shutdown									|
// |----------------------------------------------------------------------------|
bool Button::Shutdown() {

    // Shutdown parent data
    RectangleClass::Shutdown();

	debug ("Button: object shutdown.");
	return true;
}


// |----------------------------------------------------------------------------|
// |						    HandleCollision()								|
// |----------------------------------------------------------------------------|
bool Button::HandleCollision(RectangleClass* collider)
{
	
	if (m_hp > 0 ) --m_hp;

	if (m_hp <= 0)
	{
		// Change the next screen to this button's target screen
		m_parent->SetNextScreen(m_nextScreen);
		m_parent->SetDone(true);
	}

	return true;
}