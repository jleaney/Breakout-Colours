#pragma once
#include "GameState.h"

class Menu : public GameState
{
private:
	Text title;
	Text hud;

public:
	Menu(GameManager* gameManager);

	void update(Time elapsedTime) override;

	void handleInput() override;

	void draw() override;

};

