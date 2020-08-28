#include "MovingObject.h"
#include "GameManager.h"

MovingObject::MovingObject(Vector2f startPos, sf::Vector2f startSize)
{
	position = startPos;

	startPosition = position;

	// Sets initial start size
	shape.setSize(startSize);

	// Sets initial start position
	shape.setPosition(position);
	shape.setFillColor(GameManager::colours[0]);
}

// Gets the current position of each corner of the shape/object so we can check for collisions
FloatRect MovingObject::getPosition()
{
	return shape.getGlobalBounds();
}

// Returns the shape that represents the object so the main game loop can draw it
RectangleShape MovingObject::getShape()
{
	return shape;
}

// Updates the actual position of the shape
void MovingObject::update()
{
	shape.setPosition(position);
}

void MovingObject::toggleColour()
{
	currentColour = 1 - currentColour; // alternate between 0 and 1
	shape.setFillColor(GameManager::colours[currentColour]); // set colour
}

void MovingObject::reset()
{
	position = startPosition;
}
