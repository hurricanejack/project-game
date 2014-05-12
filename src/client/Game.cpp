#include "Game.hpp"

Game::Game()
{
	//currentWorld = world;
	world->SetGravity(b2Vec2(0.0f, 9.8f));
}

Game::~Game()
{

}

void Game::update(const RenderWindow& window, const Time& delta)
{
	player.update(window);
	
}

void Game::draw(RenderWindow& window)
{
	player.draw(window);
}

Player& Game::getPlayer()
{
	return player;
}