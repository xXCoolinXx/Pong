#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

enum Position {
	A, B
};

class scoreBoard : public Text
{
	int counter = 0;
public:
	scoreBoard(Position position, Window& window);

	void countUp();
	void reset();
	void draw(RenderWindow& window);

	~scoreBoard();
};

