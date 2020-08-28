#include "Menu.h"
#include "Console.h"
#include "Playing.h"
#include "AudioManager.h"

extern GameState* currentState;
extern Playing* playing;

Menu::Menu(GameManager* gameManager) : GameState(gameManager)
{
	// TITLE

	title.setFont(gameManager->font);
	title.setCharacterSize(52);
	title.setFillColor(gameManager->colours[0]);
	title.setPosition(gameManager->windowSize.x / 14, gameManager->windowSize.y / 8);
	title.setString("B R E A K O U T // colours");
	
	// Centres the origin on the y axis
	FloatRect textRect = title.getLocalBounds();
	title.setOrigin(0, textRect.height / 2);

	// HUD

	hud.setFont(gameManager->font);
	hud.setCharacterSize(35);
	hud.setFillColor(gameManager->colours[1]);
	hud.setPosition(gameManager->windowSize.x / 14, gameManager->windowSize.y / 2);
	hud.setString(
		"Match the colours to break the blocks.\n\nPress 'SPACE BAR' to toggle colours.\n'P' to pause.\n\nPress 'ENTER' to play.\n'ESC' to quit.");

	// Centres the origin on the y axis
	textRect = hud.getLocalBounds();
	hud.setOrigin(0, textRect.height / 2);
}

void Menu::update(Time timeElapsed)
{
	handleInput();

	draw();
}

void Menu::handleInput()
{
	// Start game
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		AudioManager::playSound("Begin_Game");
		currentState = playing;

		// Resets scene - object positions and active states, UI, score, lives
		currentState->start();
	}

	// Quit
	else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		renderWindow->close();
	}
}

void Menu::draw()
{
	renderWindow->clear(gameManager->backgroundColour);

	renderWindow->draw(title);
	renderWindow->draw(hud);

	renderWindow->display();
}
