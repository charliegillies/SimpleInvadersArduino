#include "BattleMode.h"
#include "ShipActor.h"
#include "InvaderActor.h"
#include "Platform.h"
#include "GameWonMode.h"
#include "GameLostMode.h"

BattleMode::BattleMode()
{
	_ship = new ShipActor(this);

	// total space the invaders take up on the zone
	int invader_world_space = (INVADERS_ON_X * INVADER_SIZE) + (INVADERS_ON_X * INVADER_SPACING_X);
	// get screen width
	int width = graphicsDevice->getScreenWidth();
	// position them relative to each other
	int initial_x = (width/2) - (invader_world_space / 2);

	for (int x = 0; x < INVADERS_ON_X; x++)
	{
		for (int y = 0; y < INVADERS_ON_Y; y++)
		{
			// calculate x & y world pos
			int x_pos = (x * INVADER_SIZE) + (x * INVADER_SPACING_X);
			int y_pos = (y * INVADER_SIZE) + (y * INVADER_SPACING_Y);

			int max_left = x_pos;

			// apply initial x
			x_pos += initial_x;

			// get the distance between this invader and the far right invader
			int dst_right = INVADERS_ON_X - x;
			// now make the full screen width - dst_right in order to get the max right position
			int max_right = width - ((dst_right * INVADER_SIZE) + (dst_right * INVADER_SIZE));

			InvaderActor* invader = new InvaderActor(_ship, x_pos, y_pos, INVADER_SIZE, max_left, max_right);

			// convert 2d index to 1d index
			_invaders[(y * INVADERS_ON_X) + x] = invader;

			// get the invader above this one in the array, if any
			// and set it's child value as this just created invader
			if (y > 0)
				_invaders[((y - 1) * INVADERS_ON_X) + x]->setChild(invader);
		}
	}
}

BattleMode::~BattleMode() {}

void BattleMode::update()
{
	// update our player ship
	_ship->update();

	int invadersAlive = 0;

	// update the enemy actors
	for (InvaderActor* invader : _invaders)
	{
		// don't iterate on dead invaders
		if (invader->isDead()) continue;

		// update the invader
		invader->update();

		// flag invader as alive
		invadersAlive++;
	}

	// set interface count
	gameInterface->setInvaderCount(invadersAlive);

	if (_ship->isDead())
	{
		setGameMode(new GameLostMode());
		return; // don't evaluate invader alive
	}

	// if all invaders are dead, end the game mode..
	if (invadersAlive <= 0)
		setGameMode(new GameWonMode());
}

InvaderActor* BattleMode::getInvader(int index)
{
	return _invaders[index];
}