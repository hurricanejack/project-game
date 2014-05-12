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
	delete currentScene;
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

void SceneManager::update(const RenderWindow& window, const Time& time)
{

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
	currentScene->draw(window);
}