#pragma once

#include "SFML/Graphics.hpp"
#include "Collectable.h"

class Game
{
public:

	void Run();

	std::vector <sf::Keyboard::Key> Keybinds =
	{
		sf::Keyboard::Key::W,		//Up
		sf::Keyboard::Key::S,		//Down
		sf::Keyboard::Key::A,		//Left
		sf::Keyboard::Key::D		//Right
	};

private:

	Collectable Collectables[3];
	const float SimSpeed = 0.13f;

};