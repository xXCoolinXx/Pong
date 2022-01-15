#include "../Headers/scoreBoard.h"

extern Font pixelFont;

scoreBoard::scoreBoard(Position position, Window& window)
{
	setString("0");
	setFont(pixelFont);
	setFillColor(Color{ 240, 240, 240 });
	setCharacterSize(40);

	if (position == A)
	{
	setPosition(Vector2f{ (window.getSize().x / 4) - getGlobalBounds().width / 2,
		window.getSize().y - getGlobalBounds().height * 2 });
	}

	if (position == B)
	{
		setPosition(Vector2f{ (window.getSize().x / 4) * 3 - getGlobalBounds().width / 2,
			window.getSize().y - getGlobalBounds().height * 2 });
	}
}

void scoreBoard::countUp()
{
	if (counter != 999)
	{
		counter++;

		setString(std::to_string(counter));
	}
}

void scoreBoard::reset()
{
	counter = 0;
}

void scoreBoard::draw(RenderWindow & window)
{
	window.draw(*this);
}

scoreBoard::~scoreBoard()
{
}
