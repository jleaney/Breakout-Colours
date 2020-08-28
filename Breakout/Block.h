#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Block
{
private:
	RectangleShape shape; // A rectangle that represents the bat

public:
	Block(Vector2f size, Vector2f position, Color colour);

	RectangleShape getShape();
	FloatRect getPosition();

	void handleImpact();

	bool active = true;
};

