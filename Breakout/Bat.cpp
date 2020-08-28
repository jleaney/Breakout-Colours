#include "Bat.h"
#include <SFML/Window.hpp>

Bat::Bat(Vector2f startPos, Vector2f startSize)
	: MovingObject(startPos, startSize)
{
	batSpeed = batSpeed;
}

// Moves bat left
void Bat::moveLeft(Time elapsedTime)
{
	position.x -= batSpeed * elapsedTime.asSeconds();
}

// Moves bat right
void Bat::moveRight(Time elapsedTime)
{
	position.x += batSpeed * elapsedTime.asSeconds();
}
