#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class MovingObject
{
protected:
	Vector2f startPosition; // the position of the bat
	Vector2f position; // the position of the bat
	RectangleShape shape; // A rectangle that represents the bat

	int currentColour = 0;

public:
	MovingObject(Vector2f startPos, Vector2f startSize); // initialises the bat with it's starting position
	
	FloatRect getPosition();
	RectangleShape getShape();
	
	void toggleColour();

	void update();

	void reset();
};

