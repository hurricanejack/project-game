#include "SceneTitle.hpp"
#include "SceneSplash.hpp"
#include "SceneTest.hpp"
#include "SceneEditor.hpp"
#include "Scenes.hpp"

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

void SceneManager::gotoScene(const int& s)
{

	// Free current scene
	if (currentScene != 0)
	{
		delete currentScene;
	}

	currentScene = 0;

	switch (s)
	{
		case SCENE_TITLE:	currentScene = new SceneTitle();	break;
		case SCENE_SPLASH:	currentScene = new SceneSplash();	break;
		case SCENE_TEST:	currentScene = new SceneTest();		break;
		case SCENE_EDITOR:	currentScene = new SceneEditor();	break;
	}

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
	int nextScene = currentScene->getNextScene();
	if (nextScene >= 0)
	{
		gotoScene(nextScene);
	}

}

void SceneManager::draw(RenderWindow& window)
{
	if (currentScene == 0){ return; }
	currentScene->draw(window);
}