#pragma once
#include <list>
#include "segment.h"
#include <SFML/Graphics.hpp>

class Snake
{
public:

	const int S_SegSize = 20;

	enum S_Directions {Up, Left, Down, Right};
	enum S_States { Alive, Dead };
	std::list<sf::Vector2f> Segments;
	
	S_States S_State = Alive;
	S_Directions S_Direction = Right;

	void MoveSnake(std::vector<sf::Keyboard::Key> Keybinds); //Direction given clockwise, 1-4.
	void DrawSnake(sf::RenderWindow& Window);

	Snake();
};