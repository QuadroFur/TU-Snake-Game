#include "Collectable.h"

void Collectable::SpawnCollectable(sf::RenderWindow& Window)
{
	sf::CircleShape Body(20 / 2);
	Body.setPosition(Position);
	Body.setFillColor(sf::Color::Cyan);
	Window.draw(Body);
}