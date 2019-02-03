#include "Game.h"

// Static functions

// Init functions
void Game::initWindow()
{
	std::ifstream ifs("config/window.ini");

	std::string title = "Unnamed";
	sf::VideoMode window_bounds(800, 600); // Underscore for local variables
	unsigned framerate_limit = 144;
	bool vertical_sync_enabled = false;

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates()
{
	this->states.push(new GameState(this->window));
}

// Constructors/destructors
Game::Game()
{
	this->initWindow();
	this->initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

// Functions
void Game::endApplication()
{
	std::cout << "Exiting program..." << std::endl;
}

void Game::updateDt()
{
	/* Updates the dt variable with the time it takes to render and update one frame. */
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
		{
			this->window->close();
		}
	}
}

void Game::update()
{
	this->updateSFMLEvents();
	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);
		if (this->states.top()->getQuit())
		{
			// Do stuff, like save character 
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	// End of game
	else
	{
		this->window->close();
		this->endApplication();
	}

}

void Game::render()
{
	this->window->clear();

	// Render to the screen
	if (!this->states.empty())
	{
		this->states.top()->render(this->window);
	}

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}


