#include <SFML/Graphics.hpp>
#include "../Headers/scoreBoard.h"
#include "../Headers/Paddle.h"
#include "../Headers/Ball.h"
#include <iostream>
using namespace sf;

Font pixelFont;

int main(void)
{
	//SFML_Main_File window
	RenderWindow window(VideoMode(800, 500), "Pong", Style::Fullscreen);

	srand(time(NULL));
	
	if (!pixelFont.loadFromFile("Assets/Fonts/pixelated.ttf"))
	{
		std::cout << "pixelFont loading failed!" << std::endl;
	}

	sf::Text escapeText;
	escapeText.setString("esc");
	escapeText.setFillColor(Color::White);
	escapeText.setFont(pixelFont);
	escapeText.setPosition(window.getSize().x - escapeText.getGlobalBounds().width - 5, 0);

	sf::RectangleShape centerLine;
	float lineThickness = 10.0f;
	centerLine.setFillColor(Color{240,240,240});
	centerLine.setPosition( (window.getSize().x - lineThickness/ 2) / 2, 0);
	centerLine.setSize( Vector2f{ lineThickness, float(window.getSize().y) });

	scoreBoard scoreBoardOne(A, window);
	scoreBoard scoreBoardTwo(B, window);

	Paddle User(window, Right);
	Paddle Computer(window, Left);

	Ball ball(window);

	Clock deltaClock;

	//Game loop
	while (window.isOpen())
	{
		int deltaTime = deltaClock.restart().asMilliseconds();

		Event event;
		//Poll the events (keyboard, mouse, etc.)
		while (window.pollEvent(event))
		{
			//Check which event type it is
			switch (event.type)
			{

				case Event::Closed:
					window.close();
				break;
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		}

		User.userControl(window);
		Computer.computerControl(window, ball.getPosition().y, deltaTime);
		
		ball.checkCollision(Computer, User);
		ball.Move(window, deltaTime);
		ball.updateScore(window, &scoreBoardOne, &scoreBoardTwo);
		

		//Clear the window so you can draw to it
		window.clear(Color::Black);

		window.draw(escapeText);
		window.draw(centerLine);

		scoreBoardOne.draw(window);
		scoreBoardTwo.draw(window);

		User.draw(window);
		Computer.draw(window);
		ball.draw(window);

		//display the window
		window.display();
	}
}