#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

using namespace sf;

class Ball: public MovingObject
{
private:

	// How fast the ball is going in the x or y dimension
	Vector2f startVelocity;
	Vector2f velocity = Vector2f(0.1, 0.1);

	Vector2f startPos;

	Time elapsedTime;

public:
	Ball(Vector2f startPos, Vector2f startSize, float startSpeed);

	float getXVelocity();

	void setVelocity(float velocity);

	void reboundSides();

	void reboundBatOrTop();

	void hitBottom();

	void update(Time elapsedTime);

	void reset();
};

