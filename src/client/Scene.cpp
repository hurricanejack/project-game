#include "Scene.hpp"

Scene::Scene()
{
	// Constructor
	nextScene = 0;
}

void Scene::update(const RenderWindow& window, const Time& time)
{
	// Do nothing
}

void Scene::draw(RenderWindow& window)
{
	// Do nothing
}

Scene* Scene::getNextScene()
{
	return nextScene;
}

void Scene::pollEvent(Event&)
{
	// Do nothing
}