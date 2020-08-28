#pragma once
#include "GameState.h"

class Playing: public GameState
{

private:
	Bat* bat;
	Ball* ball;

	int collisionsBufferAmount = 60;

	// UI

	Font font;

public:

	Text hud;

	Playing(GameManager* gameManager);

	void start() override;

	void update(Time elapsedTime) override;

	void handleInput() override;

	void handleCollisions();

	void UpdatePhysicsObjects();

	void updateUI() override;

	void draw() override;

	void checkWinState();
};