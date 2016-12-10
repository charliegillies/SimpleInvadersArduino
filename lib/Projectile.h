#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameActor.h"

class Projectile : public GameActor
{
private:
	int _yVelocity;

public:
	Projectile(int x, int y, int yVelocity);
	
	~Projectile();

	void update() override;

	bool isOccluded();
};

#endif