#include "../Headers/Ball.h"

Ball::Ball(Window & window)
{
	setFillColor(Color::White);
	setRadius(15);
	centerPosition(window);
}

void Ball::centerPosition(Window& window)
{
	setPosition(window.getSize().x / 2 - getGlobalBounds().width/2 + 2, window.getSize().y / 2 - getGlobalBounds().width/2);
	
	randomizeRadian();
}

void Ball::randomizeRadian()
{
	int randomNumber = rand() % 25;

	if (randomNumber == 5 || randomNumber == 6)
	{
		randomNumber = 8;
	}

	ballRadian = 90 * (PI * (115 + randomNumber));

	ballRadian = -ballRadian;
}

void Ball::checkBounds(Window & window)
{
	if (getPosition().y < 0)
	{
		ballRadian = -ballRadian;
		setPosition(getPosition().x, 0);
	}
	else if (getPosition().y + getGlobalBounds().height > window.getSize().y)
	{
		ballRadian = -ballRadian;
		setPosition(getPosition().x, window.getSize().y - 2*getRadius());
	}
}

void Ball::checkCollision(Paddle left, Paddle right)
{
	if (left.getGlobalBounds().intersects(getGlobalBounds()))
	{
		ballRadian = -ballRadian;
		ballDirection = -ballDirection;

		randomizeRadian();
		move(1, 0);
	}

	if (right.getGlobalBounds().intersects(getGlobalBounds()))
	{
		ballRadian = -ballRadian;
		ballDirection = -ballDirection;

		randomizeRadian();
		move(-1, 0);
	}
}

void Ball::Move(Window & window, int deltaTime)
{
	checkBounds(window);

	move(deltaTime * ballSpeed * std::cos(ballRadian) * ballDirection,
		 deltaTime * ballSpeed * std::sin(ballRadian) * ballDirection);
}

void Ball::updateScore(Window& window, scoreBoard* leftSide, scoreBoard* rightSide)
{
	if (getPosition().x <= 0)
	{
		centerPosition(window);
		rightSide->countUp();
	}

	if (getPosition().x + getGlobalBounds().width > window.getSize().x)
	{
		centerPosition(window);
		leftSide->countUp();
	}
}

void Ball::draw(RenderWindow & window)
{
	window.draw(*this);
}

Ball::~Ball()
{
	//Delete anything, if necessary
}
