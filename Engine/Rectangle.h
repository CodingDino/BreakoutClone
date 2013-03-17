// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Circle
//		Governs movement, collision detection, and drawing for a 
//      circle object. 
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

	RectangleClass ();
	// Constructor

	~RectangleClass();
	// Destructor

	bool virtual Initialize();
	// Sets up the rectangle

	int virtual draw();
	// Draws the object to the active bitmap

	int virtual logic(int mouse_x, int mouse_y);
	// Performs logic functions for the object

	void virtual ColorChange() {}
	// Changes to next color
	
	// Input functions
	int virtual onMouseDown(int button);
	int virtual onMouseUp(int button);
	int virtual onKeyDown(int button);
	int virtual onKeyUp(int button);

	bool virtual Collision(RectangleClass* collider);
	bool virtual CheckCollision(RectangleClass* collider);
	bool virtual HandleCollision(RectangleClass* collider);
	// Checks for and handles collision

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

	int m_error;			// Error code

};