#include "Snake.h"
#include <iostream>


Snake::Snake()
{
	Segments.PushBack(sf::Vector2f(100, 100));
	S_State = Alive;
}

void Snake::MoveSnake(std::vector<sf::Keyboard::Key> Keybinds)
{
	switch (S_Direction) //Moving the snake in the direction
	{
	case Snake::Up:
		for (int i = 0; i < Segments.Size(); i++) //Move to a function?
		{
			if (Segments.GetAt(i) != Segments.front() && Segments.front().x == Segments.GetAt(i).x && Segments.front().y - S_SegSize == Segments.GetAt(i).y)
			{
				S_State = Dead;
			}
		}
		Segments.PushFront(sf::Vector2f(Segments.front().x, Segments.front().y - S_SegSize));
		break;
	case Snake::Left:
		for (int i = 0; i < Segments.Size(); i++) //Move to a function?
		{
			if (Segments.GetAt(i) != Segments.front() && Segments.front().x - S_SegSize == Segments.GetAt(i).x && Segments.front().y == Segments.GetAt(i).y)
			{
				S_State = Dead;
			}
		}
		Segments.PushFront(sf::Vector2f(Segments.front().x - S_SegSize, Segments.front().y));
		break;
	case Snake::Down:
		for (int i = 0; i < Segments.Size(); i++) //Move to a function?
		{
			if (Segments.GetAt(i) != Segments.front() && Segments.front().x == Segments.GetAt(i).x && Segments.front().y + S_SegSize == Segments.GetAt(i).y)
			{
				S_State = Dead;
			}
		}
		Segments.PushFront(sf::Vector2f(Segments.front().x, Segments.front().y + S_SegSize));
		break;
	case Snake::Right:
		for (int i = 0; i < Segments.Size(); i++) //Move to a function?
		{
			if (Segments.GetAt(i) != Segments.front() && Segments.front().x + S_SegSize == Segments.GetAt(i).x && Segments.front().y == Segments.GetAt(i).y)
			{
				S_State = Dead;
			}
		}
		Segments.PushFront(sf::Vector2f(Segments.front().x + S_SegSize, Segments.front().y));
		break;
	default:
		std::cerr << "No movement set!";
	}
	Segments.PopBack();

	//Move this outside of the move function, so the direction can be changed during the render delay.
	if (sf::Keyboard::isKeyPressed(Keybinds[0]) && S_Direction != Down) //Changing direction based on key press.
		S_Direction = Up;
	if (sf::Keyboard::isKeyPressed(Keybinds[1]) && S_Direction != Up)
		S_Direction = Down;
	if (sf::Keyboard::isKeyPressed(Keybinds[2]) && S_Direction != Right)
		S_Direction = Left;
	if (sf::Keyboard::isKeyPressed(Keybinds[3]) && S_Direction != Left)
		S_Direction = Right;
}

void Snake::DrawSnake(sf::RenderWindow& Window) //drawing the snake
{
	sf::CircleShape Body(S_SegSize / 2);

	for (int i = 0; i < Segments.Size(); i++)
	{		
		Body.setPosition(Segments.GetAt(i));
		Body.setFillColor(sf::Color::Red);
		Window.draw(Body);
	}
}