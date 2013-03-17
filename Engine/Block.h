// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Block
//		Block which collides with ball and knocks it away, getting hurt or 
//		destroyed in the process.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Util.h"
#include "Rectangle.h"
#include "Screen.h"


// |----------------------------------------------------------------------------|
// |								enum BLOCK									|
// |----------------------------------------------------------------------------|
enum BLOCK {BLOCK_YELLOW, BLOCK_ORANGE, BLOCK_RED, NUM_BLOCKS};


// |----------------------------------------------------------------------------|
// |					      Class Definition: Ball							|
// |----------------------------------------------------------------------------|
class Block : public RectangleClass {
	
public:

	Block ();
	// Constructor

	~Block ();
	// De-constructor

	bool virtual Initialize();
	// Sets up the rectangle

	int virtual logic();
	// Performs logic functions for the object

	// Collision
	bool virtual HandleCollision(RectangleClass* collider);
	
	bool IsDead() { if(m_hp <= 0) return true; return false;}
	// Checks if block should be despawned
	
	void SetType(BLOCK blockType);
	// Sets the type for this block
	
protected:
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	int m_hp;
	BLOCK m_blockType;

	// Block sprites
	BitmapClass* m_yellow1;
	BitmapClass* m_orange1;	
	BitmapClass* m_orange2;	
	BitmapClass* m_red1;	
	BitmapClass* m_red2;	
	BitmapClass* m_red3;	
};
