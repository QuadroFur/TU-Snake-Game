#pragma once

#include "SFML/Graphics.hpp"
#include "Collectable.h"
#include <vector>
#include "LinkedList.h"

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

	sf::Vector2f FindFreePosition();

	std::vector<Collectable> Collectables;
	const float G_SimSpeed = 0.13f; //0.13f
	
	int G_Pass = 0;
	int G_SeaLevel = 0;
	int G_PreviousBreath = 0;

	LinkedList <sf::Vector2f> G_BreathChart;
	LinkedList <sf::Vector2f> G_ScoreChart;

};