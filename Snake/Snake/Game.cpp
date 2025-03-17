#include "Game.h"
#include "Snake.h"
#include "Collectable.h"
#include <iostream>

void Game::Run()
{
	sf::RenderWindow GraphicsWindow(sf::VideoMode({ 800, 800 }), "Snake Game!"); //Creating the snake game window.
	Snake NewSnake;

	sf::RectangleShape Water;

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

		if (UpdateClock.getElapsedTime().asSeconds() > G_SimSpeed)
		{
			if (NewSnake.S_State == NewSnake.Alive)
			{
				//
				// Code below for water dropping.
				// Advised to replace the below code with a seperate timer, which will likely occur. Wanted to learn the maths for this however, so stuck with figuring it out anyways.
				//

				G_Pass++; //A counter for the number of times the loop has passed.
				int TotalSteps = 800 / 20; //Divide the screen height by the cell size to get the number of times the water has to drop.
				float TimeOfStep = 90.0f / TotalSteps; //Divide the time the water has to drop (fixed at 90) by the number of steps that needs to be made
				float NumPasses = TimeOfStep / G_SimSpeed; //Divide the time between each step by the speed of the clock. This will not be 100% accurate.
				if (G_Pass >= NumPasses)
				{
					G_SeaLevel -= 20;
					G_Pass -= NumPasses; //This is to prevent the above inaccuracy causing error. To avoid innacuracy, SimSpeed must always be exactly divisible by TimeOfStep.
					std::cout << "Sea level dropping..." << G_SeaLevel << std::endl;
				}
				else if (G_SeaLevel <= 0)
				{
					std::cout << "The drained sea..." << std::endl;
					return;
				}

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
						NewSnake.Segments.push_back(sf::Vector2f(-20, -20));
						Collectables.erase(Collectables.begin() + i);
						std::cout << NewSnake.Segments.size() << std::endl;
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
			else
			{
				std::cout << "Watery grave..." << std::endl;
				std::cout << "The snake couldn't 'sea' anymore..." << std::endl;
				return;
			}
		}
		GraphicsWindow.clear(); //Clearing the graphics window before rendering more.

		for (Collectable i : Collectables)
			i.SpawnCollectable(GraphicsWindow);

		NewSnake.DrawSnake(GraphicsWindow); //Calling the draw function in Snake.CPP

		//Draw the water

		

		GraphicsWindow.display(); //Display output. Though this is self explanatory.
	}
	return;
}