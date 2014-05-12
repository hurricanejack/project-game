#include "Player.hpp"

Player::Player()
:GameObject()
{

	
	// Create a body for the player in the physics engine
	physics.bodyDef.type = b2_dynamicBody; //this will be a dynamic body
	physics.bodyDef.position.Set(16, 16); //set the starting position
	physics.bodyDef.angle = 0; //set the starting angle

	physics.body = world->CreateBody(&physics.bodyDef);

	b2CircleShape shape;

	shape.m_radius = 16 * (1.0f / 30.0f);

	physics.fixture.shape = &shape;
	physics.fixture.density = 1;
	physics.body->CreateFixture(&physics.fixture);

	//body->SetTransform(b2Vec2(10.0f, 10.0f), 0.0f);

	cout << "New Player" << endl;
	cout << "bodyDef = " << &physics.bodyDef << endl;
	cout << "body = " << physics.body << endl;
	cout << "fixture = " << &physics.fixture << endl;
	cout << "shape = " << &shape << endl;

	// Setup the graphics circle shape
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(2.0f);
	circle.setRadius(16.0f);
	circle.setOrigin(16, 16);

	cout << "Player::Player " << this << endl;

}
/*
Player::~Player()
{
	bodyRemoveList.push_back(physics.body);
}*/

Player::Player(const float& _x, const float& _y)
:Player()
{
	setPosition(x, y);
}

Player::Player(const Vector2<float> &vec)
:Player(vec.x, vec.y)
{

}
/*
void Player::setPosition(const Vector2<float> &position)
{
	body->SetTransform(b2Vec2(position.x * (1 / 30.0f), position.y * (1 / 30.0f)), 0.0f);
	body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
	x = position.x;
	y = position.y;
}

void Player::setPosition(const float &x, const float &y)
{
	setPosition(Vector2<float>(x, y));
}

Vector2<float> Player::getPosition()
{
	return Vector2<float>{ x, y };
}*/

void Player::update(const RenderWindow& window)
{
	GameObject::update(window);
	//cout << body->GetPosition().y << endl;

	//x = body->GetPosition().x *30;
	//y = body->GetPosition().y *30;
	circle.setPosition(x, y);

	/*Vector2<int> mouse = sf::Mouse::getPosition(window);

	float distance = pointDistance(x, y, float(mouse.x), float(mouse.y));
	float direction = pointDirection(x, y, float(mouse.x), float(mouse.y));

	if (distance > 10)
	{
		x += lengthdirX(10, direction);
		y += lengthdirY(10, direction);
	}*/

}

void Player::draw(RenderWindow& window)
{

	Vector2<int> mouse = sf::Mouse::getPosition(window);
	CircleShape c;
	c.setPosition(mouse.x, mouse.y);
	c.setRadius(10.0f);
	c.setFillColor(sf::Color::Red);
	window.draw(c);

	sf::Vertex line[2];
	line[0] = sf::Vector2f(x, y);
	line[1] = sf::Vector2f(mouse.x,mouse.y);

	line[0].color = sf::Color::Red;
	line[1].color = sf::Color::Blue;

	window.draw(line, 2, sf::Lines);

	window.draw(circle);
}
/*
sf::Vertex line[] =
{
	sf::Vertex(sf::Vector2f(10, 10)),
	sf::Vertex(sf::Vector2f(150, 150))
};*/