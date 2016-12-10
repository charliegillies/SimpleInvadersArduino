#ifndef INVADERACTOR_H
#define INVADERACTOR_H

#include "GameActor.h"
#include "Projectile.h"
#include "ShipActor.h"

class InvaderActor : public GameActor
{
private:
	InvaderActor* _child;
	Projectile* _projectile;
	ShipActor* _ship;

	bool _movingLeft;
	int _maxRight, _maxLeft;
	void applyMovement();

	int _updates, _nextShot;

	void onShoot();

public:
	InvaderActor(ShipActor *ship, int x, int y, int size, int maxLeft, int maxRight);
	~InvaderActor();

	void setChild(InvaderActor* child);

	void update() override;

	void damage();
};

#endif