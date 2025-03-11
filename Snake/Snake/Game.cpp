#include "Game.h"
#include "Snake.h"
#include "Collectable.h"
#include <iostream>

void Game::Run()
{
	sf::RenderWindow GraphicsWindow(sf::VideoMode({ 800, 800 }), "Snake Game!"); //Creating the snake game window.
	Snake NewSnake;

	sf::Clock UpdateClock;

	srand(time(NULL));

	while (GraphicsWindow.isOpen())
	{
		//Snake Game

		while (const std::optional event = GraphicsWindow.pollEvent())
		{
			if (event->is<sf::Event::Closed>()) //When closed, close.
				GraphicsWindow.close();
		}

		if (UpdateClock.getElapsedTime().asSeconds() > SimSpeed)
		{

			//Drop the water
			//90 * SimSpeed for a constant water drop speed - how many passes before the water drops again?

			NewSnake.MoveSnake(Keybinds); //Calling the move function in Snake.CPP

			/*for (Collectable i : Collectables)
			{
				if (i.Position == NewSnake.Segments.front())
				{
					NewSnake.Segments.push_back(sf::Vector2f(NewSnake.Segments.back().x + 20, NewSnake.Segments.back().y));
					Collectables
				}
			}*/
			for (int i = 0; i < Collectables.size(); i++)
			{
				if (Collectables[i].Position == NewSnake.Segments.front())
				{
					NewSnake.Segments.push_back(sf::Vector2f(NewSnake.Segments.back().x + 20, NewSnake.Segments.back().y));
					Collectables.erase(Collectables.begin() + i);
				}
			}
			for (sf::Vector2f i : NewSnake.Segments)
			{
				if (i != NewSnake.Segments.front())
				{
					if (NewSnake.Segments.front().x == i.x && NewSnake.Segments.front().y == i.y)
						return;
				}
			}
			UpdateClock.restart();

			if (rand() % 6 == 2 && Collectables.size() < 5)
			{
					Collectable NewCollectable;
					NewCollectable.Position = sf::Vector2f(rand() % (800 / 20) * 20, rand() % (800 / 20) * 20);
					Collectables.push_back(NewCollectable);
			}
		}
		GraphicsWindow.clear(); //Clearing the graphics window before rendering more.

		for (Collectable i : Collectables)
			i.SpawnCollectable(GraphicsWindow);

		NewSnake.DrawSnake(GraphicsWindow); //Calling the draw function in Snake.CPP
		GraphicsWindow.display(); //Display output. Though this is self explanatory.
	}
	return;
}