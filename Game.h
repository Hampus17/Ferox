#pragma once

#include "GameState.h"

class Game
{
private:
	// Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	// Init functions
	void initWindow();
	void initStates();

public:
	Game();
	virtual ~Game();

	// Functions -------------------

	// Regular functions
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	// Render
	void render();

	// Core
	void run();

};

