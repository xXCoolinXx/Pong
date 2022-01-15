#include "../Headers/Paddle.h"

Paddle::Paddle(Window & window, Side side)
{
	setSize(Vector2f{ 10, 70 });
	setFillColor(Color::White);

	if (side == Left)
	{
		setPosition(Vector2f{0, 0});
	}
	else if (side == Right)
	{
		setPosition(Vector2f{window.getSize().x - getGlobalBounds().width, 0});
	}
}

void Paddle::checkBounds(Window& window)
{
	if (getPosition().y + getGlobalBounds().height > window.getSize().y)
	{
		setPosition(Vector2f{getPosition().x, window.getSize().y - getGlobalBounds().height});
	}
	if (getPosition().y < 0)
	{
		setPosition(Vector2f{getPosition().x, 0});
	}
}

void Paddle::draw(RenderWindow & window)
{
	window.draw(*this);
}

void Paddle::userControl(Window& window)
{
	setPosition(getPosition().x, Mouse::getPosition(window).y - getGlobalBounds().height / 2);

	checkBounds(window);
}

void Paddle::computerControl(Window & window, float ballY, int deltaTime)
{
	if (ballY > getPosition().y)
	{
		move(0, paddleSpeed * deltaTime);
	}

	if (ballY < getPosition().y)
	{
		move(0, -paddleSpeed * deltaTime);
	}
	//TODO
}

Paddle::~Paddle()
{
}
