#pragma once
#include <SFML/Graphics.hpp>
#include "../Headers/Paddle.h"
#include "../Headers/scoreBoard.h"
#include <iostream>
#include <cmath>
using namespace sf;

const float PI = 3.14f;

class Paddle;

class Ball : public CircleShape
{
	float ballSpeed = 0.90f;
	float ballRadian = 90 * (PI / 180);
	int ballDirection = 1;
public:
	Ball(Window& window);

	void centerPosition(Window & window);
	void randomizeRadian();
	
	void checkBounds(Window& window);
	void checkCollision(Paddle left, Paddle right);
	void updateScore(Window& window, scoreBoard* leftSide, scoreBoard* rightSide);

	void Move(Window& window, int deltaTime);

	void draw(RenderWindow& window);


	~Ball();
};

