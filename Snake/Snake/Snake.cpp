#include "Snake.h"
#include <iostream>


Snake::Snake()
{
	Segments.push_back(sf::Vector2f(100, 100));
	S_State = Alive;
}

void Snake::MoveSnake(std::vector<sf::Keyboard::Key> Keybinds)
{
	switch (S_Direction) //Moving the snake in the direction
	{
	case Snake::Up:
		for (sf::Vector2f i : Segments) //Move to a function?
		{
			if (i != Segments.front() && Segments.front().x == i.x && Segments.front().y - S_SegSize == i.y)
			{
				S_State = Dead;
			}
		}
		Segments.push_front(sf::Vector2f(Segments.front().x, Segments.front().y - S_SegSize));
		break;
	case Snake::Left:
		for (sf::Vector2f i : Segments) //Move to a function?
		{
			if (i != Segments.front() && Segments.front().x - S_SegSize == i.x && Segments.front().y == i.y)
			{
				S_State = Dead;
			}
		}
		Segments.push_front(sf::Vector2f(Segments.front().x - S_SegSize, Segments.front().y));
		break;
	case Snake::Down:
		for (sf::Vector2f i : Segments) //Move to a function?
		{
			if (i != Segments.front() && Segments.front().x == i.x && Segments.front().y + S_SegSize == i.y)
			{
				S_State = Dead;
			}
		}
		Segments.push_front(sf::Vector2f(Segments.front().x, Segments.front().y + S_SegSize));
		break;
	case Snake::Right:
		for (sf::Vector2f i : Segments) //Move to a function?
		{
			if (i != Segments.front() && Segments.front().x + S_SegSize == i.x && Segments.front().y == i.y)
			{
				S_State = Dead;
			}
		}
		Segments.push_front(sf::Vector2f(Segments.front().x + S_SegSize, Segments.front().y));
		break;
	default:
		std::cerr << "No movement set!";
	}
	Segments.pop_back();

	//Move this outside of the move function, so the direction can be changed during the render delay.
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

	for (sf::Vector2f i : Segments)
	{		
		Body.setPosition(i);
		Body.setFillColor(sf::Color::Red);
		Window.draw(Body);
	}
}