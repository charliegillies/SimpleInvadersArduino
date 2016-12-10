#ifndef GAME_H
#define GAME_H

#include "Platform.h"
#include "GameMode.h"

class Game
{
private:
	GameMode* _mode;

public:
	Game(GameMode* start_mode);
	~Game();

	// changes the current game mode
	void changeMode(GameMode* mode);

	// ticks the game, this does internal logic to see if
	// the next frame should or should not be processed
	void tick();
};

#endif