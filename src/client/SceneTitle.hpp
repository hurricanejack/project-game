#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Scene.hpp"
#include "SceneTest.hpp"
#include "SceneEditor.hpp"
#include "Common.hpp"
#include "InterfaceManager.hpp"

using sf::RenderWindow;
using sf::Time;

class SceneTitle : public Scene
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	bool scaled;
	InterfaceManager interfaceManager;

public:
	SceneTitle() :Scene()
	{
		interfaceManager.setScene(this);
		interfaceManager.set(INTERFACE_MENU_MAIN);
		scaled = false;
		// Constructor
		if (!texture.loadFromFile("Resources\\gfx\\title.png"))
		{
			// TODO: Show error message
			return;
		}
		sprite.setTexture(texture);
	}

	void pollEvent(Event& event)
	{
		interfaceManager.pollEvent(event);
	}

	// Scene events
	void update(const RenderWindow& window, const Time& delta)
	{
		interfaceManager.update(window, delta);

		if (!scaled)
		{

			sf::Vector2u targetSize = window.getSize();

			// Resize image to fit screen
			sprite.setScale(
				targetSize.x / sprite.getLocalBounds().width,
				targetSize.y / sprite.getLocalBounds().height
				);

			scaled = true;
		}

		// Start a test game
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
		{
			nextScene = new SceneTest();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
		{
			nextScene = new SceneEditor();
		}

		// Stop game when the user presses Escape
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			gameRunning = false;
		}

	}

	void draw(RenderWindow& window)
	{
		window.draw(sprite);
		interfaceManager.draw(window);
	}

	void onButtonSingleplayer()
	{
		nextScene = new SceneTest();
	}

	void onButtonMultiplayer()
	{

	}

	void onButtonWorldEditor()
	{
		nextScene = new SceneEditor();
	}

	void onButtonOptions()
	{

	}

	void onButtonExit()
	{
		gameRunning = false;
	}

};


