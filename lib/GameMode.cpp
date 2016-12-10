#include "GameMode.h"
#include "Game.h"

GameMode::GameMode() {}
GameMode::~GameMode() {}

void GameMode::setGameMode(GameMode* mode)
{
	_game->changeMode(mode);
}

void GameMode::setGame(Game* game)
{
	Game* lastMode = _game;
	this->_game = game;
}