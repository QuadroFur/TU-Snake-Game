#pragma once

#include "SFML/Graphics.hpp"
#include "Collectable.h"

class Game
{
public:

	const float SimSpeed = 0.13f;
	const int CellSize = 20;

	void Run();

	sf::Keyboard::Key Keybinds[5] =
	{
		sf::Keyboard::Key::W,		//Up
		sf::Keyboard::Key::S,		//Down
		sf::Keyboard::Key::A,		//Left
		sf::Keyboard::Key::D,		//Right
		sf::Keyboard::Key::Space	//Shed Skin
	};

private:

	Collectable Collectables[3];

};