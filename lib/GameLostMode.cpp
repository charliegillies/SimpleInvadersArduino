#include "GameLostMode.h"
#include "Platform.h"

void GameLostMode::update()
{
	graphicsDevice->drawText(0, 0, "YOU LOST!");
}

GameLostMode::GameLostMode() {}

GameLostMode::~GameLostMode() {}
