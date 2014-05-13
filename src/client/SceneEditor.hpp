#pragma once

#include <Box2D\Box2D.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Scene.hpp"
#include "Common.hpp"
#include "ObjectBox.hpp"
#include <SFGUI\SFGUI.hpp>
#include <iostream>

#include "InterfaceManager.hpp"

using sf::RenderWindow;
using sf::Time;
using sf::Event;

//bool stopWorldEditor{ false };

class SceneEditor : public Scene
{
	private:
		b2World* world;
		ObjectBox* box;
		float32 timeStep = 1.0f / 60.0f;
		int32 velocityIterations = 6;
		int32 positionIterations = 2;

		InterfaceManager interfaceManager;

	public:
		SceneEditor() :Scene()
		{

			// Setup Physical world
			world = new b2World(b2Vec2(0.0f, 9.8f));

			interfaceManager.set(INTERFACE_WORLD_EDITOR_FIRST);

		}

		~SceneEditor()
		{
			if (world != 0){ delete world; }
		}

		void pollEvent(Event& event)
		{
			interfaceManager.pollEvent(event);
		}

		// Scene events
		void update(const RenderWindow& window, const Time& delta)
		{

			// Update Desktop
			interfaceManager.update(window, delta);

			// Update physics
			world->Step(timeStep, velocityIterations, positionIterations);

			// Stop game when the user presses Escape
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				//stopWorldEditor = true;
				gameRunning = false;
			}

			//if (stopWorldEditor)
			//{
				//gameRunning = false;
			//}

		}

		void draw(RenderWindow& window)
		{
			interfaceManager.draw(window);
		}

};