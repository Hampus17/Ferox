#include "State.h"

State::State(sf::RenderWindow *window)
{
	this->window = window;
	this->quitRequest = false;
}


State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quitRequest;
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quitRequest = true;
	}
}
