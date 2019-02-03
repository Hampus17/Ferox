#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class State
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;

	bool quitRequest;

public:
	State(sf::RenderWindow* window);
	virtual ~State();

	const bool &getQuit() const;

	virtual void checkForQuit();

	virtual void endState() = 0;
	virtual void updateKeybinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0; // If we want to specifically render to something, otherwise keep it a null
};

