#include "Game.h"

void Game::Run()
{
	sf::RenderWindow GraphicsWindow(sf::VideoMode({ 800, 800 }), "Adventure Game!");

	sf::Font font("arial.ttf");

	while (GraphicsWindow.isOpen())
	{
		while (const std::optional event = GraphicsWindow.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				GraphicsWindow.close();
		}
	}
}