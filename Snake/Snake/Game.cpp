#include "Game.h"
#include "Snake.h"

void Game::Run()
{
	sf::RenderWindow GraphicsWindow(sf::VideoMode({ 800, 800 }), "Snake Game!");
	Snake NewSnake;

	GraphicsWindow.setFramerateLimit(10);

	while (GraphicsWindow.isOpen())
	{
		//Snake Game

		while (const std::optional event = GraphicsWindow.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				GraphicsWindow.close();
		}

		GraphicsWindow.clear();

		NewSnake.MoveSnake();
		NewSnake.DrawSnake(GraphicsWindow);

		GraphicsWindow.display();
	}
	return;
}