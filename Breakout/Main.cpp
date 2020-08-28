#pragma once
#include "Bat.h"
#include "Ball.h"
#include "AudioManager.h"
#include "GameState.h"
#include "GameManager.h"
#include "Playing.h"
#include "Paused.h"
#include "Menu.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>
#include <list>
#include <iterator>

using namespace sf;
using namespace std;

// So all states can access other states
GameState* currentState;
Playing* playing;
Paused* paused;
Menu* menu;

// So all classes can change buffers
int inputBuffer = 0;
int collisionsBuffer = 0;

int main()
{
	// WINDOW

	Vector2i windowSize = Vector2i(VideoMode::getDesktopMode().width * 0.8, VideoMode::getDesktopMode().height * 0.8);

	RenderWindow window(VideoMode(windowSize.x, windowSize.y), "B R E A K O U T // colours - Jacob Leaney");

	// GAME MANAGER

	GameManager gameManager(&window);

	// GAME STATES

	playing = new Playing(&gameManager);
	paused = new Paused(&gameManager);
	menu = new Menu(&gameManager);

	currentState = menu;

	// AUDIO

	AudioManager audioManager("Audio/Music.wav");

	// TIME

	Clock clock;
	Time elapsedTime;

	while (window.isOpen())
	{
		// Gets delta time 
		elapsedTime = clock.getElapsedTime();
		clock.restart();

		// Runs current state
		currentState->update(elapsedTime);

		// Some buffers for input and collision
		if (inputBuffer > 0)
		{
			inputBuffer--;
		}

		if (collisionsBuffer > 0)
		{
			collisionsBuffer--;
		}
	}

	return 0;
}