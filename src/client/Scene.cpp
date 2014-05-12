#include "Scene.hpp"

Scene::Scene()
{
	// Constructor
	nextScene = 0;
}

void Scene::update(const RenderWindow& window, const Time& time)
{

}

void Scene::draw(RenderWindow& window)
{

}

Scene* Scene::getNextScene()
{
	return nextScene;
}