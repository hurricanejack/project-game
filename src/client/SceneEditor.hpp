#pragma once

#include <Box2D\Box2D.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Scene.hpp"
#include "Common.hpp"
#include "ObjectBox.hpp"

using sf::RenderWindow;
using sf::Time;

class SceneEditor : public Scene
{
private:
	b2World* world;
	ObjectBox* box;
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

public:
	SceneEditor() :Scene()
	{
		world = new b2World(b2Vec2(0.0f, 9.8f));
	}

	~SceneEditor()
	{
		delete world;
	}

	// Scene events
	void update(const RenderWindow& window, const Time& delta)
	{

		// Update physics
		world->Step(timeStep, velocityIterations, positionIterations);

		// Stop game when the user presses Escape
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			gameRunning = false;
		}

	}

	void draw(RenderWindow& window)
	{

	}

};