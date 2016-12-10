#ifndef GAMEMODE_H
#define GAMEMODE_H

class Game;

// the current mode that the game is on
class GameMode
{
private:
	// reference to game parent that owns the mode
	Game* _game;

protected:
	// sets the game mode without providing access to game
	void setGameMode(GameMode* mode);

public:
	GameMode();
	virtual ~GameMode();

	// overrideable method to 
	virtual void update() = 0;

	// sets the game parent to allow the mode to change
	void setGame(Game* game);
};

#endif