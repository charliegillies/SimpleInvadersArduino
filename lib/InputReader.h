#ifndef INPUT_H
#define INPUT_H

class InputReader
{
public:
	virtual ~InputReader() {}
	InputReader() { }

	// if the player is trying to move left
	virtual bool movedLeft() = 0;
	
	// if the player is trying to move right
	virtual bool movedRight() = 0;

	// if the player is trying to fire
	virtual bool fired() = 0;
};

#endif