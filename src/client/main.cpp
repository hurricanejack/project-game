#include "Common.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <conio.h>
#include "Game.hpp"
#include <vector>

using std::vector;
using sf::RenderWindow;
using sf::Time;
using sf::Event;
using sf::Clock;
using sf::Color;
using std::to_string;
using sf::Font;

int main()
{

	gameRunning = true;

	Game game;

	Font defaultFont;

	if (!defaultFont.loadFromFile("ARIAL.TTF"))
	{
		cout << "Failed to load font." << endl;
		_getch();
		return -1;
	}

	// Figure out which screen resolution to go for
	vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	RenderWindow window(modes.at(0), "ProjectGame Alpha R1", sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);

	// Declare a window
	//RenderWindow window(sf::VideoMode(1280, 720), "ProjectGame Alpha R1", sf::Style::Titlebar | sf::Style::Close);

	//window.create(sf::VideoMode(1920, 1080), "ProjectGame Alpha R1", sf::Style::Fullscreen);

	// Delta timer
	Clock tickClock;
	Clock fpsClock;
	Clock timer;
	float frameCounter = 0;
	float deltaCounter = 0;
	int frames = 0;
	int ticks = 0;
	
	sf::CircleShape circle;
	circle.setRadius(20.0f);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(5.0f);

	while (gameRunning)
	{

		sf::Clock c;

		mouse.update(window);

		circle.setPosition(mouse.x, mouse.y);

		Time elapsed = timer.restart();
		deltaCounter += elapsed.asMicroseconds();

		while (deltaCounter > frameTime)
		{
			frameCounter++;
			deltaCounter -= frameTime;
		}

		// Poll window events
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case Event::Closed:
				{
					gameRunning = false;
				}
				break;
				case Event::MouseButtonPressed:
				{

				}
				break;
			}
			if (!gameRunning){ break; }
		}

		// Update object states
		while (frameCounter > 0) // Frames to update
		{
			game.update(window, c.getElapsedTime());
			frameCounter--;
			ticks++;
			c.restart();
		}

		sf::Text text;
		text.setFont(defaultFont);
		text.setColor(Color::Black);
		text.setString("FPS: "+to_string(fps)+" TPS: "+to_string(tps));
		text.setPosition(30.0f, 30.0f);

		// Display objects
		window.clear(Color::White);
		game.draw(window);
		window.draw(circle);
		window.draw(text);
		window.display();

		frames++;

		if (fpsClock.getElapsedTime().asSeconds() >= 1)
		{
			fpsClock.restart();
			fps = frames;
			frames = 0;
		}

		if (tickClock.getElapsedTime().asSeconds() >= 1)
		{
			tickClock.restart();
			tps = ticks;
			ticks = 0;
		}

	}

	// Close the game window
	if (window.isOpen())
	{
		window.close();
	}

	return 0;
}