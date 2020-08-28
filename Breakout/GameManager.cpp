#include "GameManager.h"
#include <iostream>
#include "Console.h"

const Color GameManager::colours[] = { Color(20, 20, 20), Color(235, 235, 235) };

GameManager::GameManager(RenderWindow* renderWindow)
{
	GameManager::renderWindow = renderWindow;

	windowSize = Vector2i(GameManager::renderWindow->getSize());

	// Sets up new bat - position & size
	bat = new Bat(Vector2f(windowSize.x / 2, windowSize.y * 0.9), batSize);

	// Sets up new ball - position, size, starting velocity
	ball = new Ball(Vector2f(windowSize.x / 2, windowSize.y * 0.8), ballSize, 500);

	// Font to be be used by all UI
	font.loadFromFile("Fonts/OpenSans-Bold.ttf");

	// Creates block that player is to break
	GameManager::initBlocks(4);
}

void GameManager::initBlocks(int rows)
{
	int blockWidth = 150;
	float minDist = 10;

	// Calculates how many blocks will fit in a row, including a gap (minDist)
	int blocksPerRow = windowSize.x / (blockWidth + minDist);
	
	int fullSize = blockWidth + minDist; // the full size of a block, including the block and the gap
	minDist += windowSize.x % fullSize / blocksPerRow; // sets the size of the gap based on how much leftover space there is

	// The spawn position of a block
	Vector2f spawnPos = Vector2f(0, minDist);

	// So we can toggle between 2 elements in an array
	int currentColour = 0;

	// Creates a new row, with a space between each
	for (int j = 0; j < rows; j++)
	{
		// Creates horizontal row of blocks, with a spacer
		for (int i = 0; i < blocksPerRow; i++)
		{
			// Sets placement position of first block, so it only has a small gap from side of window
			if (i == 0)
			{
				spawnPos.x = minDist / 2;
			}

			// Position of every other block 
			else
			{
				spawnPos.x += minDist;

			}

			// Instantiates block - size, position, and colour
			blocks.push_back(new Block(Vector2f(blockWidth, 50), spawnPos, colours[currentColour]));
			currentColour = 1 - currentColour; // toggles between two colours

			// Adds the block size to the next spawn position
			spawnPos.x += blockWidth;
		}

		// Adds a spacer between each row
		spawnPos.y += 50 + minDist;
	}
}
