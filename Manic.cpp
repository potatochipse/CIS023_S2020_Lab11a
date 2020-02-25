#include "framework.h"
#include "CIS023_S2020_Lab11a.h"

void Manic::Start(HWND hWnd)
{
	iFrame = 0;									// Reset frame count

	Initialize(hWnd, BOX);						// Initialize base class with a box
}

bool Manic::Move(HWND hWnd)
{
	RECT rClient;								// Window size
	RECT rNew;									// After move
	POINT pMove;								// How much to move

	GetClientRect(hWnd, &rClient);				// Get windows specs

	ChangeSize(1);								// Gets bigger every frame

	// Set how much to move
	pMove.x = GetRandomInt(-30, 30);			// Move horz
	pMove.y = GetRandomInt(-30, 30);			// Move vert

	rNew = ChangeLocation(pMove);				// Move command in base class

	// End point
	if (++iFrame > 100)							// Max # of moves
		return false;							// Restart

	return true;								// Keep running
}
