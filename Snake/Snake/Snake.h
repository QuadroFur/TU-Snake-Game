#pragma once
#include <list>
#include "segment.h"
#include <SFML/Graphics.hpp>
#include "LinkedList.h"

class Snake
{
public:

	int Breath = 120;
	const int S_SegSize = 20;

	enum S_Directions {Up, Left, Down, Right};
	enum S_States { Alive, Dead };
	LinkedList<sf::Vector2f>Segments;
	
	S_States S_State = Alive;
	S_Directions S_Direction = Right;

	void MoveSnake(int SeaLevel, Snake& OtherSnake);
	void DrawSnake(sf::RenderWindow& Window);

	Snake();
};