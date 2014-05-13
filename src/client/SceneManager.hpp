#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Scene.hpp"

using sf::RenderWindow;
using sf::Time;
using sf::Event;

class SceneManager
{

	private:
		Scene* currentScene;

	public:
		SceneManager();
		~SceneManager();

		void gotoScene(const int&);	// Force the scene manager to goto a specific scene

		// Scene manager events
		void pollEvent(Event&);
		void update(const RenderWindow&, const Time&);
		void draw(RenderWindow&);

};