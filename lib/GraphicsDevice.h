#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H

class GraphicsDevice
{
	short _screenW, _screenH;

public:
	GraphicsDevice(int screen_w, int screen_h) 
		: _screenW(screen_w), _screenH(screen_h) {}
	
	virtual ~GraphicsDevice() {}

	// function to draw a rectangle of a specific size in a specific (x,y) position
	virtual void drawRect(int x, int y, int width, int height) = 0;

	// function to draw a line from (x0,y0) to (x1,y1)
	virtual void drawLine(int x0, int y0, int x1, int y1) = 0;

	// function to draw text in a given (x, y) position
	virtual void drawText(int x, int y, char* str) = 0;

	// function to begin the display operations
	virtual void begin() = 0;

	// function to end the display operations
	virtual void end() = 0;

	// function to get the screen width property
	short getScreenWidth()
	{
		return _screenW;
	}

	// function to get the screen height property
	short getScreenHeight()
	{
		return _screenH;
	}
};

#endif