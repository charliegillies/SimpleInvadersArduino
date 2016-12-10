#ifndef BATTLEMODE_H
#define BATTLEMODE_H

#include "GameMode.h"

// how many invaders spawn on the x axis
const int INVADERS_ON_X = 6;
// how many invaders spawn on the y axis
const int INVADERS_ON_Y = 3;
// the size of each invader in px (w and h)
const int INVADER_SIZE = 8;
// the spacing between every invader on the X axis
const int INVADER_SPACING_X = 6;
// the spacing between every invader on the y axis
const int INVADER_SPACING_Y = 2;
// shorthand for INVADERS ON X * INVADERS ON Y
const int INVADER_TOTAL = INVADERS_ON_X * INVADERS_ON_Y;
// Invaders will shoot between every 1 and 3 seconds
const float MAX_SHOOT_TIME = 3;
const float MIN_SHOOT_TIME = 1;

class ShipActor;
class InvaderActor;
class Projectile;

class BattleMode : public GameMode
{
private:
	// the player controlled ship
	ShipActor* _ship;
	// a fixed array of invader actors
	InvaderActor* _invaders[INVADER_TOTAL];

public:
	BattleMode();
	~BattleMode();

	void update() override;

	InvaderActor* getInvader(int index);
};

#endif