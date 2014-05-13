#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Scene.hpp"
#include "Scenes.hpp"
#include "Common.hpp"

using sf::RenderWindow;
using sf::Time;

class SceneSplash : public Scene
{
	private:
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Clock clock;
		bool scaled;

	public:
		SceneSplash() :Scene()
		{
			scaled = false;
			// Constructor
			if (!texture.loadFromFile("Resources\\gfx\\splash.png"))
			{
				// TODO: Show error message
				return;
			}
			sprite.setTexture(texture);
		}

		// Scene events
		void update(const RenderWindow& window, const Time& delta)
		{
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

			if (isKeyPressedAny() || clock.getElapsedTime().asSeconds() >= 5.0f)
			{
				nextScene = SCENE_TITLE;
			}

		}

		void draw(RenderWindow& window)
		{
			window.draw(sprite);
		}

};