#pragma once
#include "SFML/Graphics.hpp"

class Collectable
{

public:

	enum Type {Food, Treasure};
	int Weight = 1;

	sf::Vector2f Position;

	void SpawnCollectable(sf::RenderWindow& Window);

};

