#pragma once

#include "SFML/Graphics.hpp"

class Game
{
public:

	void Run();

	sf::Keyboard::Key Keybinds[5] =
	{
		sf::Keyboard::Key::W,		//Up
		sf::Keyboard::Key::S,		//Down
		sf::Keyboard::Key::A,		//Left
		sf::Keyboard::Key::D,		//Right
		sf::Keyboard::Key::Space	//Shed Skin
	};
};