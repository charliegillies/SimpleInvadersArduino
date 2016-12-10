#ifndef GAMEWONMODE_H
#define GAMEWONMODE_H

#include "GameMode.h"

class GameWonMode :	public GameMode
{
public:
	void update() override;

	GameWonMode();
	~GameWonMode();
};

#endif