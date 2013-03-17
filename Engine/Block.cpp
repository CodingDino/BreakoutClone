// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Block
//		Block which collides with ball and knocks it away, getting hurt or 
//		destroyed in the process.


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Block.h"
#include <cmath>

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Block::Block() :
	m_yellow1(0),
	m_orange1(0),
	m_orange2(0),
	m_red1(0),
	m_red2(0),
	m_red3(0)
{
	debug ("Block: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Block::~Block() {
	debug ("Block: instance destroyed.");
}


// |----------------------------------------------------------------------------|
// |							   Initialize									|
// |----------------------------------------------------------------------------|
bool Block::Initialize() {
	
	// Hit Points
	m_hp = 1;

	// Set dimmensions
	m_dimmensions.x = 50*SCALE_X;
	m_dimmensions.y = 20*SCALE_Y;
	
	// Loading graphics into Image objects
	m_yellow1 = new BitmapClass();
	m_yellow1->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/block_yellow1.png", m_dimmensions.x, m_dimmensions.y);
	m_orange2 = new BitmapClass();
	m_orange2->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/block_orange2.png", m_dimmensions.x, m_dimmensions.y);
	m_orange1 = new BitmapClass();
	m_orange1->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/block_orange1.png", m_dimmensions.x, m_dimmensions.y);
	m_red3 = new BitmapClass();
	m_red3->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/block_red3.png", m_dimmensions.x, m_dimmensions.y);
	m_red2 = new BitmapClass();
	m_red2->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/block_red2.png", m_dimmensions.x, m_dimmensions.y);
	m_red1 = new BitmapClass();
	m_red1->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/block_red1.png", m_dimmensions.x, m_dimmensions.y);
	
	// Default Type
	m_blockType;
	m_graphic = m_yellow1;

	// Set location
	m_position.x = (SCREEN_WIDTH - m_dimmensions.x)/2;
	m_position.y = SCREEN_HEIGHT-SCREEN_HEIGHT*0.3;

	debug ("Block: object initialized.");

	return true;
}

// |----------------------------------------------------------------------------|
// |							    logic()										|
// |----------------------------------------------------------------------------|
int Block::logic() {
	debug ("Block: logic() called.", 10);

	return m_error;
}


// |----------------------------------------------------------------------------|
// |						    HandleCollision()								|
// |----------------------------------------------------------------------------|
bool Block::HandleCollision(RectangleClass* collider)
{
	
	if (m_hp > 0 ) 
	{
		--m_hp;
		if (m_blockType == BLOCK_ORANGE)
		{
			m_graphic = m_orange1;

			// Orange changes ball color
			collider->ColorChange();
		}
		else if (m_blockType == BLOCK_RED)
		{
			if (m_hp == 2)
				m_graphic = m_red2;
			else m_graphic = m_red1;
		}
	}

	return true;
}

// |----------------------------------------------------------------------------|
// |								SetType()									|
// |----------------------------------------------------------------------------|
void Block::SetType(BLOCK blockType)
{
	m_blockType = blockType;

	if (blockType == BLOCK_YELLOW)
	{
		m_graphic = m_yellow1;
		m_hp = 1;
	}
	else if (blockType == BLOCK_ORANGE)
	{
		m_graphic = m_orange2;
		m_hp = 2;
	}
	else if (blockType == BLOCK_RED)
	{
		m_graphic = m_red3;
		m_hp = 3;
	}
}