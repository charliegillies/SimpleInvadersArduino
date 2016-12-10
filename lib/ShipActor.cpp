#include "ShipActor.h"
#include "Platform.h"
#include "Projectile.h"
#include "BattleMode.h"
#include "InvaderActor.h"

const int PROJ_VELOCITY = -3;

ShipActor::ShipActor(BattleMode* battleMode)
{
	_lives = MAX_LIVES;

	// set the initial counter
	gameInterface->setLivesCounter(_lives);

	_projectile = nullptr;

	_battleMode = battleMode;

	int height = graphicsDevice->getScreenHeight();

	size = 10;
	y = (height - size);
	x = 0;
}

ShipActor::~ShipActor() {}

void ShipActor::damage()
{
	// remove a life
	_lives--;

	// if our lives are 0 or less, we're dead -- game over.
	dead = _lives <= 0;

	// set the counter on the interface
	gameInterface->setLivesCounter(_lives);
}

void ShipActor::update()
{
	graphicsDevice->drawRect(x, y, size, size);

	// if we have a projectile child, update it
	if (_projectile != nullptr)
	{
		// update the projectile
		_projectile->update();

		// Now we want to iterate over the invaders to see if our projectile has collided..
		for (int i = 0; i < INVADER_TOTAL; i++)
		{
			// get the invader
			InvaderActor* invader = _battleMode->getInvader(i);

			// skip if the invader has been killed
			if (invader->isDead()) continue;

			// test collision & apply result
			if (invader->intersects(_projectile))
			{
				// kill invader
				invader->damage();

				// delete projectile on collision
				delete _projectile;
				_projectile = nullptr;

				// break the loop, as we've matched our condition
				break;
			}
		}

		// another nullptr check incase it collided & was destroyed
		// if the projectile is out of screen, delete it
		if (_projectile != nullptr && _projectile->isOccluded())
		{
			delete _projectile;
			_projectile = nullptr;
		}
	}

	if (inputReader->fired())
	{
		// if we have no projectile at the moment, create one
		if (_projectile == nullptr)
			_projectile = new Projectile(x + (size / 2), y, PROJ_VELOCITY);
	}
	else if (inputReader->movedLeft())
	{
		x -= 5;

		// ensure we're in x bounds
		if (x < 0)
			x = 0;
	}
	else if (inputReader->movedRight())
	{
		x += 5;

		int width = graphicsDevice->getScreenWidth();
		// ensure we're in x bounds
		if ((x + size) > width)
			x = width - size;
	}

}