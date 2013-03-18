// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
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

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   Methods   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Constructors and Destructors
	Block();
	Block(const Block&);
	~Block();

    // Initialization and shutdown
	bool virtual Initialize();
	bool virtual Shutdown();
    
	// Performs logic functions for the object
	bool virtual Logic();
	
	// Checks if block should be despawned
	bool IsDead() { if(m_hp <= 0) return true; return false;}

	// Collision
	bool virtual HandleCollision(RectangleClass* collider);
	
    // Setter Functions
	void SetType(BLOCK blockType);
	
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
