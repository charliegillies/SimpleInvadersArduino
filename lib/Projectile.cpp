#include "Projectile.h"
#include "Platform.h"

Projectile::Projectile(int x, int y, int yVelocity)
{
	this->x = x;
	this->y = y;
	this->size = 2;
	this->_yVelocity = yVelocity;
}

Projectile::~Projectile() {}

void Projectile::update()
{
	// draw the projectile
	graphicsDevice->drawRect(x, y, size, size);

	// apply velocity
	y += _yVelocity;
}

bool Projectile::isOccluded()
{
	// check if we've gone out of bounds on the y axis
	return (y + size) < 0 || y > graphicsDevice->getScreenHeight();
}