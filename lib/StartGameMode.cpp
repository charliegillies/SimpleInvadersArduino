#include "StartGameMode.h"
#include "Platform.h"
#include "BattleMode.h"

StartGameMode::StartGameMode() {}
 
StartGameMode::~StartGameMode() {}

void StartGameMode::update()
{
	graphicsDevice->drawText(0, 0, "SPACE INVADERS");
	graphicsDevice->drawText(0, 20, "PRESS ANY BUTTON");

	// change to the battle mode
	if (inputReader->movedLeft() || inputReader->movedRight() || inputReader->fired())
		setGameMode(new BattleMode());
}