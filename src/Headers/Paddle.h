#pragma once
#include <SFML/Graphics.hpp>
#include "../Headers/Ball.h"
using namespace sf;

enum Side 
{
	Left, Right
};

class Paddle : public RectangleShape
{
	float paddleSpeed = 0.71f;
public:
	Paddle(Window& window, Side side);

	void checkBounds(Window& window);

	void draw(RenderWindow& window);
	
	void userControl(Window& window);
	void computerControl(Window& window, float ballY, int deltaTime);

	~Paddle();
};

