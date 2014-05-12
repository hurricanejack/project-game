#pragma once

#include "Common.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Box2D\Box2D.h>


using sf::Vector2;
using sf::CircleShape;
using sf::RenderWindow;
using sf::Time;

class Player: public GameObject
{

	private:
		float x{ 0 }, y{ 0 };
		CircleShape circle;
		/*
		b2CircleShape shape;
		b2FixtureDef fixture;
		b2BodyDef bodyDef;
		b2Body* body;*/

	public:
		Player();
		//~Player();
		Player(const Vector2 <float>&);
		Player(const float&, const float&);

		// Setters
		//void setPosition(const Vector2<float>&);
		//void setPosition(const float&, const float&);

		// Getters
		//Vector2<float> getPosition();

		// Updaters
		void update(const RenderWindow&);

		// Drawing
		void draw(RenderWindow&);
};

