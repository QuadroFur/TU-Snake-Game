#include "Snake.h"
#include <iostream>
#include <SFML/Graphics.hpp>

void Snake::MoveSnake(sf::Keyboard::Key* Keybinds)
{
	switch (S_Direction) //Moving the snake in the direction
	{
	case Snake::Up:
		S_Position.y = S_Position.y - S_SegSize;
		break;
	case Snake::Left:
		S_Position.x = S_Position.x - S_SegSize;
		break;
	case Snake::Down:
		S_Position.y = S_Position.y + S_SegSize;
		break;
	case Snake::Right:
		S_Position.x = S_Position.x + S_SegSize;
		break;
	default:
		std::cerr << "No movement set!";
	}

	if (sf::Keyboard::isKeyPressed(Keybinds[0]) && S_Direction != Down) //Changing direction based on key press.
		S_Direction = Up;
	else if (sf::Keyboard::isKeyPressed(Keybinds[1]) && S_Direction != Up)
		S_Direction = Down;
	else if (sf::Keyboard::isKeyPressed(Keybinds[2]) && S_Direction != Right)
		S_Direction = Left;
	else if (sf::Keyboard::isKeyPressed(Keybinds[3]) && S_Direction != Left)
		S_Direction = Right;
}

void Snake::DrawSnake(sf::RenderWindow& Window) //drawing the snake
{
	sf::CircleShape Body(S_SegSize / 2);
	Body.setPosition(S_Position);
	Body.setFillColor(sf::Color::Red);
	Window.draw(Body);
}