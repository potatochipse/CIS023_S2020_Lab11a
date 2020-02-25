// Module:		Sphere.cpp
// Author:		Mark Berrett
// Date:		February 24, 2020
// Purpose:		Implimentation file for Sphere
//				Base class
//				Start and default values for elypse
//
// Updates: Miguel Antonio Logarta
//			February 24, 2020
//			Lab 11a - Inheritance
//

#include "framework.h"
#include "CIS023_S2020_Lab11a.h"

void Sphere::Initialize(HWND hWnd, int iType)
{
	iFigure = iType;								// BOX or BALL

	// get client window dimensions
	RECT rClient;
	GetClientRect(hWnd, &rClient);					// window

	// default start at center of window
	rDim.left = (rClient.right / 2) - 20;
	rDim.top = (rClient.bottom / 2) - 20;
	rDim.right = rDim.left + 40;
	rDim.bottom = rDim.top + 40;

	// set color
	r = GetRandomInt(0, 255);
	g = GetRandomInt(0, 255);
	b = GetRandomInt(0, 255);
}

RECT Sphere::ChangeLocation(POINT pChange)
{
	// pChange.x,y amount
	rDim.left += pChange.x;
	rDim.top += pChange.y;
	rDim.right += pChange.x;
	rDim.bottom += pChange.y;

	return rDim;					// return new location
}

bool Sphere::ChangeSize(int iChange)
{
	// if change size is 1, then grow/shrink bottom right
	if (abs(iChange) == 1)
	{
		rDim.bottom += iChange;
		rDim.right += iChange;
	}
	else				// else shrink/grow all 4 sides
	{
		rDim.left -= iChange / 2;
		rDim.top -= iChange / 2;
		rDim.right += iChange / 2;
		rDim.bottom += iChange / 2;
	}

	// if size <= 0, then return false
	if (rDim.right <= rDim.left ||
		rDim.bottom <= rDim.top)
		return false;

	return true;				// bigger than 0
}

void Sphere::Draw(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(r, g, b));
	HBRUSH oldBrush;
	oldBrush = (HBRUSH)SelectObject(hdc, brush);

	// draw
	if (iFigure == BOX)
		FillRect(hdc, &rDim, brush);
	else
		Ellipse(hdc, rDim.left, rDim.top, rDim.right, rDim.bottom);

	SelectObject(hdc, oldBrush);
	DeleteObject(brush);
}

RECT Sphere::GetInvalidateRect()
{
	rReturn = rDim;						// start with current size

	// expand to accound for movement
	rReturn.left -= 40;
	rReturn.top -= 40;
	rReturn.right += 40;
	rReturn.bottom += 40;

	return rReturn;						// return new (larger) rectangle
}

int Sphere::GetRandomInt(int iMin, int iMax)
{
	random_device rd;								// non-deterministic generator
	mt19937 gen(rd());								// to seed mersenne twister.
	uniform_int_distribution<> dist(iMin, iMax);	// distribute results inside center rect

	return dist(gen);								// return random # between iMin and iMax

}
