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
class Rectangle {

public:

	Rectangle ();
	// Constructor

	~Rectangle();
	// Destructor

	bool Initialize();
	// Sets up the rectangle

	int virtual draw();
	// Draws the object to the active bitmap

	int virtual logic(int mouse_x, int mouse_y);
	// Performs logic functions for the object
	
	// Input functions
	int virtual onMouseDown(int button);
	int virtual onMouseUp(int button);
	int virtual onKeyDown(int button);
	int virtual onKeyUp(int button);

	// Getter functions
	Coord GetPosition() {return m_position; }
	Coord GetDimmensions() {return m_dimmensions; }

	// Setter functions
	void virtual setPosition(Coord new_position);
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	Coord m_position;		// Position of the center of the circle
	Coord m_velocity;		// Velocity of the circle (updates the position in the logic function)
	Coord m_dimmensions;	// Position of the center of the circle

	BitmapClass* m_graphic;	// Graphic

	int m_error;			// Error code

};