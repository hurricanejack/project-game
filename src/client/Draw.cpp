#include "Draw.hpp"

void drawLine(RenderWindow& window, const float& x1, const float& y1, const float& x2, const float& y2, const sf::Color& color)
{
	sf::Vertex line[2];
	line[0] = sf::Vertex(sf::Vector2f(x1, x2));
	line[1] = sf::Vertex(sf::Vector2f(y1, y2));
	line[0].color = color;
	line[1].color = color;
	window.draw(line, 2, sf::Lines);
}