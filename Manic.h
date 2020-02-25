// Module:	Bounce.h
// Author:	Miguel Antonio Logarta
// Date:	February 24, 2020
// Purpose: Header file for Manic.cpp
//			Inherited from Sphere class
//			Calculates absurd movement
//

#pragma once

class Manic :
	public Sphere
{
public:
	void Start(HWND);											// Set initial values
	bool Move(HWND);											// Move the graphic

private:
	int iFrame;													// # of times the graphic has moved

};

