#pragma once

#include <iostream>

struct Coordinate
{
	float x, y;

	Coordinate():x(0.0f), y(0.0f) {}

	Coordinate(float p_x, float p_y):x(p_x), y(p_y) {}
};