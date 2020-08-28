#include "Paused.h"
#include "Playing.h"
#include "Menu.h"

extern GameState* currentState;
extern Playing* playing;
extern Menu* menu;
extern int inputBuffer;

Paused::Paused(GameManager* gameManager) : GameState(gameManager)
{
	bat = gameManager->bat;
	ball = gameManager->ball;

	// Set up UI
	hud.setFont(gameManager->font);
	hud.setCharacterSize(35);
	hud.setFillColor(gameManager->colours[1]);

	hud.setPosition(gameManager->windowSize.x / 14, gameManager->windowSize.y / 2);

	hud.setString("Press 'BACKSPACE' to return to menu.\n'P' to continue.\n\n'ESC' to quit.");

	FloatRect textRect = hud.getLocalBounds();
	hud.setOrigin(0, textRect.height / 2);
}

void Paused::update(Time timeElapsed)
{
	Paused::handleInput();

	Paused::draw();
}

void Paused::handleInput()
{
	Event event;
	while (renderWindow->pollEvent(event) && event.type == Event::KeyPressed)
	{
		if (Keyboard::isKeyPressed(Keyboard::P))
		{
			currentState = playing;
		}

		else if (Keyboard::isKeyPressed(Keyboard::BackSpace))
		{
			currentState = menu;
		}

		else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			renderWindow->close();
		}
	}
}

void Paused::draw()
{
	renderWindow->clear(gameManager->backgroundColour);

	renderWindow->draw(ball->getShape());
	renderWindow->draw(bat->getShape());

	// Draws active blocks only
	for (Block* block : gameManager->blocks)
	{
		if (block->active)
		{
			renderWindow->draw(block->getShape());
		}
	}

	renderWindow->draw(playing->hud);
	renderWindow->draw(hud);

	renderWindow->display();
}
