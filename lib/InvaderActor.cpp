#include "InvaderActor.h"
#include "Platform.h"
#include "stdlib.h"

InvaderActor::InvaderActor(ShipActor *ship, int x, int y, int size, int maxLeft, int maxRight) 
{
	this->_ship = ship;

	this->x = x;
	this->y = y;
	this->size = size;

	this->_maxLeft = maxLeft;
	this->_maxRight = maxRight;
	this->_movingLeft = true;

	this->_projectile = nullptr;
	this->_child = nullptr;

	this->_updates = 0;

	// generate using rand
	this->_nextShot = (rand() % 48) + 1;
}

InvaderActor::~InvaderActor() {}

void InvaderActor::setChild(InvaderActor* child)
{
	this->_child = child;
}

void InvaderActor::applyMovement()
{
	if (_movingLeft)
	{
		x -= 1;

		if (x <= _maxLeft)
			_movingLeft = false;
	}
	else
	{
		x += 1;

		if ((x + size) >= _maxRight)
			_movingLeft = true;
	}
}

void InvaderActor::onShoot()
{
	_projectile = new Projectile(x + (size / 2), y + size + 1, 1);

	// reset counter to 0
	this->_updates = 0;
	// generate using rand
	this->_nextShot = (rand() % 48) + 1;
}

void InvaderActor::update()
{
	// apply invader shift
	applyMovement();

	graphicsDevice->drawRect(x, y, size, size);

	// If our child invader is still alive, do nothing
	if (_child == nullptr || _child->isDead()) return;

	// Otherwise, fire projectiles!
	if (_projectile != nullptr)
	{
		_projectile->update();

		// check if our projectile has hit the ship
		if (_projectile->intersects(_ship))
		{
			// if it has, damage the ship
			_ship->damage();

			// delete the projectile, set to nullptr
			delete _projectile;
			_projectile = nullptr;
		}

		// _projectile may have been deleted, if not, check if it's occluded
		// and if it is, delete it
		if (_projectile != nullptr && _projectile->isOccluded())
		{
			delete _projectile;
			_projectile = nullptr;
		}
	}
	else
	{
		// increment updates by 1
		_updates++;

		// cheap hack to see if we can shoot or not
		if (_updates == _nextShot)
			onShoot();
	}
}

void InvaderActor::damage()
{
	// set dead to true, stops update()
	dead = true;
}