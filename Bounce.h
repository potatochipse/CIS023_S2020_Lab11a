// Module:	Bounce.h
// Author:	Miguel Antonio Logarta
// Date:	February 24, 2020
// Purpose: Header file for Bounce.cpp
//			Inherited from Sphere class
//			Calculates movement
//

#pragma once
#include "Sphere.h"
class Bounce :
	public Sphere
{
public:
	void Start(HWND);							// Start movement 
	bool Move(HWND);							// Calculate new location, return FALSE to start over

private:
	POINT pSpeed;								// Speed and direction
	int iFrame;									// # of times the graphic has moved


};

