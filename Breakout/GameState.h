#pragma once
#include "GameManager.h"

class GameState
{
protected:
	RenderWindow* renderWindow;
	Time elapsedTime;

public:

	GameState(GameManager* gameManager);
	
	GameManager* gameManager;
	
	virtual void start();

	virtual void update(Time elapsedTime);

	virtual void handleInput();

	virtual void updateUI();
	
	virtual void draw();
};
