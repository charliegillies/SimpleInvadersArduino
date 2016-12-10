#include "GameActor.h"


bool GameActor::intersects(GameActor* actor)
{
	// what we're testing against
	int r2Left = actor->x;
	int r2Right = r2Left + actor->size;
	int r2top = actor->y;
	int r2bot = r2top + actor->size;

	// what we're 
	int r1left = x;
	int r1Right = r1left + size;
	int r1top = y;
	int r1bot = y + size;

	return !(r2Left > r1Right ||
		r2Right < r1left ||
		r2top > r1bot ||
		r2bot < r1top);
}

bool GameActor::isDead()
{
	return dead;
}

GameActor::GameActor()
{
	this->dead = false;
}

GameActor::~GameActor()
{
}
