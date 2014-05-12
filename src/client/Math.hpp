#pragma once

#define PI 3.14159265

#include <SFML/System.hpp>
#include <math.h>

using sf::Vector2;

float pointDirection(const float &x1, const float &y1, const float &x2, const float &y2);
float pointDirection(const Vector2<float>& p1, const Vector2<float>& p2);
float sqr(const float &value);
float pointDistance(const float &x1, const float &y1, const float &x2, const float &y2);
float pointDistance(const Vector2<float>& p1, const Vector2<float>& p2);
float lengthdirX(const float &length, const float &direction);
float lengthdirY(const float &length, const float &direction);