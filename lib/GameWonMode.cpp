#include "GameWonMode.h"
#include "Platform.h"

void GameWonMode::update()
{
	graphicsDevice->drawText(0, 0, "YOU WON!");
}

GameWonMode::GameWonMode() {}

GameWonMode::~GameWonMode() {}
