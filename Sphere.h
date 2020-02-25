// Module:		Sphere.h
// Author:		Mark Berrett
// Date:		February 24, 2020
// Purpose:		Header file for Sphere.cpp
//				Base class
//				Start and default values for elypse
//
// Updates: Miguel Antonio Logarta
//			February 24, 2020
//			Lab 11a - Inheritance
//

#pragma once
class Sphere
{
public:
	void Initialize(HWND, int);					// set initial size, location, color
	RECT ChangeLocation(POINT);				// move x,y, returns new location
	bool ChangeSize(int);					// change size by int amount, return false if size = 0
	void Draw(HDC);							// draw elypse
	int GetRandomInt(int, int);					// return random integer
	RECT GetInvalidateRect();				// return rect for paint


private:
	int iFigure;							// BOX or BALL
	RECT rDim;								// location and size of star
	int r, g, b;							// color
	RECT rReturn;							// return value for GetInvalidateRect()

};

