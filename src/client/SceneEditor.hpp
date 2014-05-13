#pragma once

#include <Box2D\Box2D.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Scene.hpp"
#include "Common.hpp"
#include "ObjectBox.hpp"
#include <SFGUI\SFGUI.hpp>
#include <iostream>
#include "WorldEditor.hpp"
#include "WorldEditorObject.hpp"
#include "Scenes.hpp"

#include "InterfaceManager.hpp"
#include "SceneTitle.hpp"

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
		WorldEditor worldEditor;
		

	public:
		SceneEditor() :Scene()
		{

			interfaceManager.setScene(this);
			

			// Setup Physical world
			world = new b2World(b2Vec2(0.0f, 9.8f));

			interfaceManager.set(INTERFACE_WORLD_EDITOR_FIRST);

			

			WorldEditorObject test;
			test.getProperties(). addProperty("id", "0");
			test.getProperties().addProperty("name", "Crate");
			test.getProperties().addProperty("width", "32");

			worldEditor.addObject(test);

			//InterfaceWorldEditor* editor = reinterpret_cast<InterfaceWorldEditor*>(interfaceManager.getInterface());
			//editor->setProperties(test.getProperties());

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

			Scene::update(window, delta);

			// Update Desktop
			interfaceManager.update(window, delta);

			// Update physics
			world->Step(timeStep, velocityIterations, positionIterations);

			// Stop game when the user presses Escape
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				//stopWorldEditor = true;

				interfaceManager.set(INTERFACE_WORLD_EDITOR_FIRST);

				//gameRunning = false;
			}

			//if (stopWorldEditor)
			//{
				//gameRunning = false;
			//}

		}

		void onButtonNewProject()
		{

			// Clear the current level


			// Now setup a new one
			if (!worldEditor.newProject())
			{
				// Show error message
				return;
			}

			// Change interface
			interfaceManager.set(INTERFACE_WORLD_EDITOR_MAIN);
			interfaceManager.setUser(reinterpret_cast<void*>(&worldEditor));

		}

		void onButtonLoadProject()
		{

			// Clear the current level


			// Now load
			if (!worldEditor.loadProject())
			{
				// Show error message
				return;
			}

		}

		void onButtonPublishProject()
		{

			// Now setup a new one
			if (!worldEditor.publishProject())
			{
				// Show error message
				return;
			}

		}

		void onButtonExitWorldEditor()
		{
			nextScene = SCENE_TITLE;
		}

		void draw(RenderWindow& window)
		{
			interfaceManager.draw(window);
		}

};