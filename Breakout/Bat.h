#pragma once

#include <SFML/Graphics.hpp>
#include "MovingObject.h"

using namespace sf;

class Bat: public MovingObject
{
private:
	float batSpeed = 1000; // movement speed of the bat

public:
	Bat(Vector2f startPos, Vector2f startSize);

	void moveLeft(Time elapsedTime);
	void moveRight(Time elapsedTime);
};