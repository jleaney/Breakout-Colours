#pragma once
#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"
#include "Block.h"
#include <list>

using namespace sf;

class GameManager
{
private:
	void initBlocks(int rows);

public:
	GameManager(RenderWindow* renderWindow);
	RenderWindow* renderWindow;

	Vector2i windowSize;

	int score = 0;
	int lives = 3;

	Vector2f batSize = Vector2f(100, 20);
	Vector2f ballSize = Vector2f(30, 30);

	Bat* bat;
	Ball* ball;

	Font font; // Font to be used by all UI

	std::vector<Block*> blocks;

	const static Color colours[];

	Color backgroundColour = Color(109, 128, 171);
};

