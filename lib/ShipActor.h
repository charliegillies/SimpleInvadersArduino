#ifndef SHIPACTOR_H
#define SHIPACTOR_H

#include "GameActor.h"

class Projectile;
class InvaderActor;
class BattleMode;

class ShipActor : public GameActor
{
private:
	Projectile* _projectile;
	BattleMode* _battleMode;
	const int MAX_LIVES = 3;
	int _lives = MAX_LIVES;

public:
	ShipActor(BattleMode* battle_mode);
	~ShipActor();

	void damage();

	void update() override;
};

#endif