#include "Game.hpp"
#include "Scenes.hpp"

Game::Game()
{
	splash = true;
	scene.gotoScene(new SceneSplash());
}

Game::~Game()
{

}

void Game::update(const RenderWindow& window, const Time& delta)
{

	// Only show splash screen for 5 seconds
	if (splashClock.getElapsedTime().asSeconds() >= 5.0f && splash)
	{
		scene.gotoScene(new SceneTitle());
		splash = false;
	}

	scene.update(window, delta);

}

void Game::draw(RenderWindow& window)
{
	scene.draw(window);
}

