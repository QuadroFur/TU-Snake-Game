#include "Snake.h"
#include <iostream>


Snake::Snake()
{
	Segments.PushBack(sf::Vector2f(100, 100));
	S_State = Alive;
}

void Snake::MoveSnake(int SeaLevel, Snake& OtherSnake)
{
	switch (S_Direction) //Moving the snake in the direction
	{
	case Snake::Up:
		for (int i = 0; i < Segments.Size(); i++) //Move to a function?
		{
			if (Segments.GetAt(i) != Segments.front() && Segments.front().x == Segments.GetAt(i).x && Segments.front().y - S_SegSize == Segments.GetAt(i).y)
				S_State = Dead;
			else if (Segments.GetAt(i).x == OtherSnake.Segments.front().x && Segments.GetAt(i).y == OtherSnake.Segments.front().y)
				OtherSnake.S_State = Dead;
		}
		Segments.PushFront(sf::Vector2f(Segments.front().x, Segments.front().y - S_SegSize));
		break;
	case Snake::Left:
		for (int i = 0; i < Segments.Size(); i++) //Move to a function?
		{
			if (Segments.GetAt(i) != Segments.front() && Segments.front().x - S_SegSize == Segments.GetAt(i).x && Segments.front().y == Segments.GetAt(i).y)
				S_State = Dead;
			else if (Segments.GetAt(i).x == OtherSnake.Segments.front().x && Segments.GetAt(i).y == OtherSnake.Segments.front().y)
				OtherSnake.S_State = Dead;
		}
		Segments.PushFront(sf::Vector2f(Segments.front().x - S_SegSize, Segments.front().y));
		break;
	case Snake::Down:
		for (int i = 0; i < Segments.Size(); i++) //Move to a function?
		{
			if (Segments.GetAt(i) != Segments.front() && Segments.front().x == Segments.GetAt(i).x && Segments.front().y + S_SegSize == Segments.GetAt(i).y)
				S_State = Dead;
			else if (Segments.GetAt(i).x == OtherSnake.Segments.front().x && Segments.GetAt(i).y == OtherSnake.Segments.front().y)
				OtherSnake.S_State = Dead;
		}
		Segments.PushFront(sf::Vector2f(Segments.front().x, Segments.front().y + S_SegSize));
		break;
	case Snake::Right:
		for (int i = 0; i < Segments.Size(); i++) //Move to a function?
		{
			if (Segments.GetAt(i) != Segments.front() && Segments.front().x + S_SegSize == Segments.GetAt(i).x && Segments.front().y == Segments.GetAt(i).y)
				S_State = Dead;
			else if (Segments.GetAt(i).x == OtherSnake.Segments.front().x && Segments.GetAt(i).y == OtherSnake.Segments.front().y)
				OtherSnake.S_State = Dead;
		}
		Segments.PushFront(sf::Vector2f(Segments.front().x + S_SegSize, Segments.front().y));
		break;
	default:
		std::cerr << "No movement set!";
	}
	if (Segments.front().y < SeaLevel - 20)
		if (Segments.Size() != 1)
			Segments.PopBack();
		else
			S_State = Dead;
	Segments.PopBack();
}

void Snake::DrawSnake(sf::RenderWindow& Window) //drawing the snake
{
	sf::RectangleShape Body(sf::Vector2f(S_SegSize, S_SegSize));

	for (int i = 0; i < Segments.Size(); i++)
	{
		Body.setPosition(Segments.GetAt(i));
		Body.setFillColor(sf::Color::Red);
		Window.draw(Body);
	}
}