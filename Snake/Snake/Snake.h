#pragma once
#include <list>
#include "segment.h"
#include <SFML/Graphics.hpp>

class Snake
{
public:

	const int S_SegSize = 20.0f;

	enum S_Directions {Up, Left, Down, Right};
	
	S_Directions S_Direction = Right;
	sf::Vector2f S_Position = { 100.0f, 100.0f };

	void MoveSnake(sf::Keyboard::Key* Keybinds); //Direction given clockwise, 1-4.
	void DrawSnake(sf::RenderWindow& Window);
};