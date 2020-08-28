#include "Playing.h"
#include "Paused.h"
#include "Menu.h"
#include "Block.h"
#include <iostream>
#include <sstream>
#include "Console.h"

extern GameState* currentState;
extern Paused* paused;
extern Menu* menu;

extern int inputBuffer;
extern int collisionsBuffer;

using namespace std;

Playing::Playing(GameManager* gameManager) : GameState(gameManager)
{
	bat = gameManager->bat;
	ball = gameManager->ball;

	// Set up score and lives UI
	hud.setFont(gameManager->font);
	hud.setCharacterSize(24);
	hud.setFillColor(gameManager->colours[1]);
	hud.setPosition(gameManager->windowSize.x * 0.025, gameManager->windowSize.y * 0.95);
}

// Resets scene - item positions and active states, score, lives
void Playing::start()
{
	gameManager->score = 0;
	gameManager->lives = 0;
	bat->reset();
	ball->reset();

	for (Block* block : gameManager->blocks)
	{
		block->active = true;
	}
}

void Playing::update(Time elapsedTime)
{
	Playing::elapsedTime = elapsedTime;

	Playing::handleInput();

	Playing::handleCollisions();

	Playing::UpdatePhysicsObjects();

	Playing::updateUI();

	Playing::draw();
}

void Playing::handleInput()
{
	// Move left and right
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		bat->moveLeft(elapsedTime);
	}

	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		bat->moveRight(elapsedTime);
	}

	// Only calls on frame that key was pressed down
	Event event;
	while (renderWindow->pollEvent(event))
	{
		// Toggle colour of bat and ball
		if (event.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				bat->toggleColour();
				ball->toggleColour();
			}

			// Pause game
			else if (Keyboard::isKeyPressed(sf::Keyboard::P))
			{
				if (inputBuffer == 0)
				{
					currentState = paused;
					inputBuffer = 360;
				}
			}

			// Quit application
			else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				renderWindow->close();
			}
		}
	}
}

void Playing::handleCollisions()
{
	// Buffer so multiple collisions can't happen within a few frames
	//if (collisionsBuffer != 0) return;

	// Handles ball hitting bottom
	if (ball->getPosition().top > gameManager->windowSize.y)
	{
		// Reverses ball direction
		ball->hitBottom();

		// Lose a life
		gameManager->lives--;

		// Checks for zero lives
		if (gameManager->lives < 1)
		{
			// Resets score and lives
			//gameManager->score = 0;
			//gameManager->lives = 3;
		}

		collisionsBuffer = collisionsBufferAmount;
	}

	// Handles ball hitting top or bat
	if (ball->getPosition().top < 0)
	{
		ball->reboundBatOrTop();

		collisionsBuffer = collisionsBufferAmount;
	}

	// Handles ball hitting sides
	if (ball->getPosition().left < 0 
		|| ball->getPosition().left + gameManager->ballSize.x > gameManager->windowSize.x)
	{
		ball->reboundSides();

		collisionsBuffer = collisionsBufferAmount;
	}

	// Handles ball hitting bat
	if (ball->getPosition().intersects(bat->getPosition()))
	{
		ball->reboundBatOrTop();
		// Bat hit sound

		collisionsBuffer = collisionsBufferAmount;
	}

	// Checks if ball interacts with any block
	for (Block* block : gameManager->blocks)
	{
		if (ball->getPosition().intersects(block->getPosition()) && block->active)
		{
			ball->reboundBatOrTop();

			if (ball->getShape().getFillColor() == block->getShape().getFillColor())
			{
				block->handleImpact();
				gameManager->score++;

				if (currentState != menu)
				{
					checkWinState();
				}

				break;
			}
		}
	}
}

// Updates the position of the ball and bat
void Playing::UpdatePhysicsObjects()
{
	ball->update(elapsedTime);
	bat->update();
}

// Updates the UI text
void Playing::updateUI()
{
	std::stringstream ss;
	ss << "Score: " << gameManager->score << "     Lives: " << gameManager->lives;
	hud.setString(ss.str());
}

// Draws all visuals
void Playing::draw()
{
	renderWindow->clear(gameManager->backgroundColour);

	renderWindow->draw(ball->getShape());
	renderWindow->draw(bat->getShape());

	for (Block* block : gameManager->blocks)
	{
		if (block->active)
		{
			renderWindow->draw(block->getShape());
		}
	}

	renderWindow->draw(hud);

	renderWindow->display();
}

// Checks whether all blocks have been hit
void Playing::checkWinState()
{
	if (gameManager->score >= gameManager->blocks.size())
	{	
		currentState = menu;
	}
}