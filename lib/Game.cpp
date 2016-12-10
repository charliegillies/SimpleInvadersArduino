#include "Game.h"

Game::Game(GameMode* start_mode)
{
	changeMode(start_mode);
}

Game::~Game() {}

void Game::changeMode(GameMode* mode)
{
	// set game as self inside of the mode
	mode->setGame(this);
	// set the internal mode to be this
	_mode = mode;
}

void Game::tick()
{
	// clear the graphics device..
	graphicsDevice->begin();

	// update the game mode
	_mode->update();

	// end the graphics drawing..
	graphicsDevice->end();
}