#include "Ball.h"
#include <iostream>
#include "AudioManager.h"
#include <SFML/Window.hpp>

using namespace std;

Ball::Ball(Vector2f startPos, Vector2f startSize, float startSpeed) 
	: MovingObject(startPos, startSize)
{ 
	velocity.x = startSpeed;
	velocity.y = startSpeed;

	startVelocity = velocity; // so we can come back to the original velocity on reset

	Ball::startPos = startPos;
}

float Ball::getXVelocity()
{
	return velocity.x;
}

void Ball::setVelocity(float newVelocity)
{
	velocity.x = newVelocity;
	velocity.y = newVelocity;
}

// Reverses the ball's horizontal direction on collision with walls
void Ball::reboundSides()
{
	velocity.x = -velocity.x;
	AudioManager::playSound("Hit_Wall");
}

// Reverses the ball's vertical direction on collision with top, bat, or blocks
void Ball::reboundBatOrTop()
{
	//position.y -= (velocity.y * 30  * elapsedTime.asSeconds());
	velocity.y = -velocity.y;

	AudioManager::playSound("Hit_Bat");
}

// Handles hitting bottom of screen
void Ball::hitBottom()
{
	position = startPos;

	velocity.y = -velocity.y;

	AudioManager::playSound("Fail");
}

// Updates actual position of ball
void Ball::update(Time elapsedTime)
{
	Ball::elapsedTime = elapsedTime;

	position.x += velocity.x * elapsedTime.asSeconds();
	position.y += velocity.y * elapsedTime.asSeconds();

	MovingObject::update();
}

// Reset ball position and direction
void Ball::reset()
{
	MovingObject::reset();

	velocity = startVelocity;
}




