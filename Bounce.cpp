// Module:	Bounce.cpp
// Author:	Miguel Antonio Logarta
// Date:	February 24, 2020
// Purpose: Implementation file for Sphere
//			Inherited from Sphere class
//			Calculates movement
//

#include "framework.h"
#include "CIS023_S2020_Lab11a.h"

void Bounce::Start(HWND hWnd)
{
	// Set x speed
	do
	{
		pSpeed.x = GetRandomInt(-25, 25);						// Speed either left to right up to 25
	} while (abs(pSpeed.x) < 5);								// Speed may not be less than 5

	// Set y speed
	do
	{
		pSpeed.y = GetRandomInt(-25, 25);						// Speed either up or down up to 25
	} while (abs(pSpeed.y) < 5);								// Speed may not be less than 5

	iFrame = 0;													// Initialize iFrame

	Initialize(hWnd, BALL);										// Call base class to set rest of values
}

bool Bounce::Move(HWND hWnd)
{
	RECT rClient;												// Main window
	RECT rNew;													// After move

	if (++iFrame % 3 == 0)										// Shrink graphic every 5 moves
		if (!ChangeSize(-1))									// True if size > 0
			return FALSE;										// False if graphic is gone

	rNew = ChangeLocation(pSpeed);								// Set new rect values in base class

	GetClientRect(hWnd, &rClient);								// Get window size

	// Bounce off the walls
	if (rNew.left <= 0)											// Hit left wall
		pSpeed.x *= -1;											// Change direction to the right
	if (rNew.top <= 0)											// Hit the top
		pSpeed.y *= -1;											// Change directino to down
	if (rNew.bottom >= rClient.bottom)							// Hit bottom
		pSpeed.y *= -1;											// Change direction to up

	if (rNew.right > rClient.right)								// Hit the right wall
		return false;											// Force a restart

	return TRUE;												// Continue moving
}
