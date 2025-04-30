#pragma once
#include "SFML/Graphics.hpp"

class Collectable
{

public:

	int Score = 0;

	sf::Vector2f Position;

	Collectable();
	void SpawnCollectable(sf::RenderWindow& Window);

};

