#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

// Abstract UI handler
class GameInterface
{
public:
	GameInterface() {}
	virtual ~GameInterface() {}

	virtual void setLivesCounter(int lives) = 0;

	virtual void setInvaderCount(int count) = 0;
};

#endif