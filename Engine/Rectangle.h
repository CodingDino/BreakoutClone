// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// Rectangle
//		Governs movement, collision detection, and drawing for a 
//      Rectangle object. 
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Util.h"
#include "Coord.h"
#include "graphicsclass.h"
#include "D3DClass.h"


// |----------------------------------------------------------------------------|
// |						Class Definition: Rectangle							|
// |----------------------------------------------------------------------------|
class RectangleClass {

public:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   Methods   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Constructors and Destructors
	RectangleClass();
	RectangleClass(const RectangleClass&);
	~RectangleClass();

    // Initialization and shutdown
	bool virtual Initialize();
	bool virtual Shutdown();
    
	// Draws the object to the active bitmap
	bool virtual Draw();
    
	// Performs logic functions for the object
	bool virtual Logic();
    
	// Stub for ball color change function
	void virtual ColorChange() {}
    
	// Collision
	bool virtual Collision(RectangleClass* collider);
	bool virtual CheckCollision(RectangleClass* collider);
	bool virtual HandleCollision(RectangleClass* collider);

	// Getter functions
	Coord GetPosition() {return m_position; }
	Coord GetDimmensions() {return m_dimmensions; }
	Coord GetVelocity() {return m_velocity; }

	// Setter functions
	void virtual SetPosition(Coord new_position) {m_position = new_position;}
	void virtual SetDimmensions(Coord new_dimmensions) {m_dimmensions = new_dimmensions;}
	
protected:
    
	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	Coord m_position;		// Position of the center of the circle
	Coord m_velocity;		// Velocity of the circle (updates the position in the logic function)
	Coord m_dimmensions;	// Position of the center of the circle

	BitmapClass* m_graphic;	// Graphic

};