#include "Block.h"
#include "AudioManager.h"

Block::Block(Vector2f size, Vector2f position, Color colour)
{
	shape.setSize(size);
	shape.setPosition(position);
	shape.setFillColor(colour);
}

// On collision with ball when it has matching colour
void Block::handleImpact()
{
	AudioManager::playRandomBlockBreak();
	active = false;
}

RectangleShape Block::getShape()
{
	return shape;
}

FloatRect Block::getPosition()
{
	return shape.getGlobalBounds();
}

