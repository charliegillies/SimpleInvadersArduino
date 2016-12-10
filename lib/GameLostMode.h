#ifndef GAMELOSTMODE_H
#define GAMELOSTMODE_H

#include "GameMode.h"

class GameLostMode : public GameMode
{
public:
	void update() override;

	GameLostMode();
	~GameLostMode();
};

#endif