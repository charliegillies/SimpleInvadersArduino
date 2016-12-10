#ifndef GAMEACTOR_H
#define GAMEACTOR_H

#include "stdint.h"

class GameActor
{
protected:
	bool dead;
	// position & collision
	int x, y, size;

public:
	bool intersects(GameActor* actor);

	bool isDead();

	GameActor();
	virtual ~GameActor();

	// Update method for all actors
	virtual void update() = 0;
};

#endif