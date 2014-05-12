#include "Common.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.hpp"
#include <string>
#include <conio.h>
#include "Game.hpp"
#include "Body.hpp"

using sf::RenderWindow;
using sf::Time;
using sf::Event;
using sf::Clock;
using sf::Color;
using std::to_string;
using sf::Font;

int main()
{

	if (!defaultFont.loadFromFile("ARIAL.TTF"))
	{
		cout << "Failed to load font." << endl;
		_getch();
		return -1;
	}

	b2BodyDef def;
	def.position.Set(0.0f, 0.0f);
	b2Body* ground = world->CreateBody(&def);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(800.0f, 50.0f);
	b2FixtureDef fix;
	fix.shape = &groundBox;
	fix.density = 0.0f;
	ground->CreateFixture(&fix);
	ground->SetTransform(b2Vec2(0.0f, 400.0f), 0.0f);

	Player player2{ 20.0f, 20.0f };
	//player2.setPosition(-100.0f, -200.0f);

	// Declare a window
	RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	Game game;

	// Delta timer
	Clock tickClock;
	Clock fpsClock;
	Clock timer;
	float frameCounter = 0;
	float deltaCounter = 0;
	int frames = 0;
	int ticks = 0;

	while (window.isOpen())
	{

		player2.setPosition({ 20.0f, 20.0f });

		mouse.update(window);

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
					window.close();
				}
				break;
				case Event::MouseButtonPressed:
				{
					game.getPlayer().setPosition(mouse.x,mouse.y);
				}
				break;
			}
		}

		// Update object states
		while (frameCounter > 0) // Frames to update
		{
			game.update(window, elapsed);
			player2.update(window);
			frameCounter--;
			ticks++;
		}
		//1000 / frameTime
		world->Step(elapsed.asSeconds(), 6, 2);

		removeBodies();

		sf::Text text;
		text.setFont(defaultFont);
		text.setColor(Color::Black);
		text.setString("FPS: "+to_string(fps)+" TPS: "+to_string(tps));
		text.setPosition(30.0f, 30.0f);

		// Display objects
		window.clear(Color::White);
		game.draw(window);
		player2.draw(window);
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

	delete world;

	return 0;
}