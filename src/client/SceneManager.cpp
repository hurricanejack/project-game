#include "SceneManager.hpp"
#include <iostream>
using namespace std;

SceneManager::SceneManager()
{

	// Init variables
	currentScene	= 0;

}

SceneManager::~SceneManager()
{
	if (currentScene != 0)
	{
		delete currentScene;
	}
}

void SceneManager::gotoScene(Scene* scene)
{

	// Free current scene
	if (currentScene != 0)
	{
		delete currentScene;
	}

	// Replace current scene
	currentScene = scene;
}

void SceneManager::pollEvent(Event& event)
{
	if (currentScene == 0){ return; }
	currentScene->pollEvent(event);
}

void SceneManager::update(const RenderWindow& window, const Time& time)
{
	if (currentScene == 0){ return; }

	// Update scene
	currentScene->update(window, time);
	
	// Check for next scene
	Scene* nextScene = currentScene->getNextScene();
	if (nextScene != 0)
	{
		gotoScene(nextScene);
	}

}

void SceneManager::draw(RenderWindow& window)
{
	if (currentScene == 0){ return; }
	currentScene->draw(window);
}