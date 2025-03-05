#include "Snake.h"
#include <iostream>

Snake::Snake()
{
	Segments.push_back(sf::Vector2f(100, 100));
}

void Snake::MoveSnake(sf::Keyboard::Key* Keybinds)
{
	switch (S_Direction) //Moving the snake in the direction
	{
	case Snake::Up:
		Segments.push_front(sf::Vector2f(Segments.front().x, Segments.front().y - S_SegSize));
		Segments.pop_back();
		break;
	case Snake::Left:
		Segments.push_front(sf::Vector2f(Segments.front().x - S_SegSize, Segments.front().y));
		Segments.pop_back();
		break;
	case Snake::Down:
		Segments.push_front(sf::Vector2f(Segments.front().x, Segments.front().y + S_SegSize));
		Segments.pop_back();
		break;
	case Snake::Right:
		Segments.push_front(sf::Vector2f(Segments.front().x + S_SegSize, Segments.front().y));
		Segments.pop_back();
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
	for (sf::Vector2f i : Segments)
	{
		sf::CircleShape Body(S_SegSize / 2);
		Body.setPosition(i);
		Body.setFillColor(sf::Color::Red);
		Window.draw(Body);
	}
}