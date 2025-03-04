#include "Game.h"
#include "Snake.h"

void Game::Run()
{
	sf::RenderWindow GraphicsWindow(sf::VideoMode({ 800, 800 }), "Snake Game!"); //Creating the snake game window.
	Snake NewSnake;

	sf::Clock UpdateClock;

	//GraphicsWindow.setFramerateLimit(10); //A temporary line to view the movement of the snake, before I add the timer.

	while (GraphicsWindow.isOpen())
	{
		//Snake Game

		while (const std::optional event = GraphicsWindow.pollEvent())
		{
			if (event->is<sf::Event::Closed>()) //When closed, close.
				GraphicsWindow.close();
		}

		if (UpdateClock.getElapsedTime().asSeconds() > SimSpeed) //
		{
			NewSnake.MoveSnake(Keybinds); //Calling the move function in Snake.CPP
		}
		GraphicsWindow.clear(); //Clearing the graphics window before rendering more.
		NewSnake.DrawSnake(GraphicsWindow); //Calling the draw function in Snake.CPP
		GraphicsWindow.display(); //Display output. Though this is self explanatory.
	}
	return;
}