#include "Scene.hpp"

Scene::Scene()
{
	// Constructor
	nextScene = -1;
	guiWidth = 0;
	guiHeight = 0;
}

void Scene::update(const RenderWindow& window, const Time& time)
{
	// Do nothing
	if (guiWidth == 0 || guiHeight == 0)
	{
		guiWidth = window.getSize().x;
		guiHeight = window.getSize().y;
	}
}

void Scene::draw(RenderWindow& window)
{
	// Do nothing
}

int Scene::getNextScene()
{
	return nextScene;
}

void Scene::pollEvent(Event&)
{
	// Do nothing
}

int Scene::getGUIWidth()
{
	return guiWidth;
}

int Scene::getGUIHeight()
{
	return guiHeight;
}
