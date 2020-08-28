#pragma once
#include "GameState.h"
class Paused: public GameState
{

private:
	Bat* bat;
	Ball* ball;

	Text hud;

public:
	Paused(GameManager* gameManager);

	void handleInput() override;

	void update(Time elapsedTime) override;

	void draw() override;
};

