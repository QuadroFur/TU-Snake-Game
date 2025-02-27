#include "Snake.h"
#include <iostream>
#include <SFML/Graphics.hpp>

void Snake::MoveSnake()
{
	switch (S_Direction)
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		S_Direction = Up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		S_Direction = Down;
	}

}

void Snake::DrawSnake(sf::RenderWindow& Window)
{
	sf::CircleShape Body(S_SegSize / 2);
	Body.setPosition(S_Position);
	Body.setFillColor(sf::Color::Red);
	Window.draw(Body);
}