#ifndef STARTGAMEMODE_H
#define STARTGAMEMODE_H

#include "GameMode.h"

class StartGameMode : public GameMode
{
public:
	StartGameMode();
	~StartGameMode();

	void update() override;
};

#endif