#include "Collectable.h"
#include <iostream>

void Collectable::SpawnCollectable(sf::RenderWindow& Window)
{
	sf::CircleShape Body(20 / 2);
	Body.setPosition(Position);
	if (Score == 1)
		Body.setFillColor(sf::Color::Cyan);
	else
		Body.setFillColor(sf::Color::Magenta);
	Window.draw(Body);
}
Collectable::Collectable()
{
	srand(time(NULL));
	if (rand() % 8 == 5)
		Score = 2;
	else
		Score = 1;
}