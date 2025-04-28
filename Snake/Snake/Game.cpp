#include "Game.h"
#include "Snake.h"
#include "Collectable.h"
#include <iostream>
#include <cstdlib>

void Game::Run()
{
	sf::RenderWindow GraphicsWindow(sf::VideoMode({ 800, 800 }), "Snake Game!"); //Creating the snake game window.
	sf::RectangleShape Water;
	sf::Clock UpdateClock;

	Snake PlrSnake;
	Snake AISnake;

	Water.setFillColor(sf::Color(0, 165, 255, 80));
	Water.setPosition(sf::Vector2f(0, 0));
	Water.setSize(sf::Vector2f(800, 800));

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
			if (PlrSnake.S_State == PlrSnake.Alive) //&& AISnake.S_State == AISnake.Alive)
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
					G_SeaLevel += 20;
					G_Pass -= NumPasses; //This is to prevent the above inaccuracy causing error. To avoid innacuracy, SimSpeed must always be exactly divisible by TimeOfStep.
					Water.setPosition(sf::Vector2f(0, G_SeaLevel));
				}
				else if (G_SeaLevel >= 800)
				{
					std::cout << "The drained sea..." << std::endl;
					return;
				}

				//Player Snake Controls & Move
				if (sf::Keyboard::isKeyPressed(Keybinds[0]) && PlrSnake.S_Direction != Snake::Down) //Changing direction based on key press.
					PlrSnake.S_Direction = Snake::Up;
				else if (sf::Keyboard::isKeyPressed(Keybinds[1]) && PlrSnake.S_Direction != Snake::Up)
					PlrSnake.S_Direction = Snake::Down;
				else if (sf::Keyboard::isKeyPressed(Keybinds[2]) && PlrSnake.S_Direction != Snake::Right)
					PlrSnake.S_Direction = Snake::Left;
				else if (sf::Keyboard::isKeyPressed(Keybinds[3]) && PlrSnake.S_Direction != Snake::Left) 
					PlrSnake.S_Direction = Snake::Right;
				PlrSnake.MoveSnake(G_SeaLevel, AISnake); //Calling the move function in Snake.CPP

				//AI Snake Direction & Movement

				//Find Closest Collectable
				int ClosestCollectable = -1;
				int ClosestPos = 800;
				for (int i = 0; i < Collectables.size(); i++)
				{
					int XDiff = std::abs(AISnake.Segments.front().x - Collectables[i].Position.x);
					int YDiff = std::abs(AISnake.Segments.front().y - Collectables[i].Position.y);

					if (XDiff + YDiff < ClosestPos)
					{
						ClosestPos = XDiff + YDiff;
						ClosestCollectable = i;
					}
				}

				//Either move towards the collectable or surface.
				if (ClosestCollectable != -1 && AISnake.Breath > G_SeaLevel / 20) //Check if the snake can grab the collectable and return in time.
				{
					std::cout << "Collectable found & Breath good" << std::endl;
					std::cout << Collectables[ClosestCollectable].Position.x << " + " << Collectables[ClosestCollectable].Position.y << std::endl;
					int XDir = AISnake.Segments.front().x - Collectables[ClosestCollectable].Position.x;
					int YDir = AISnake.Segments.front().y - Collectables[ClosestCollectable].Position.y;

					std::cout << XDir << " + " << YDir << std::endl;

					if (XDir != 0)
					{
						std::cout << "Moving X" << std::endl;
						if (XDir > 0 && AISnake.S_Direction != AISnake.Right)
						{
							AISnake.S_Direction = AISnake.Left;
							std::cout << "Moving -X" << std::endl;
						}
						else if (XDir < 0 && AISnake.S_Direction != AISnake.Left)
						{
							AISnake.S_Direction = AISnake.Right;
							std::cout << "Moving +X" << std::endl;
						}
						else
						{
							std::cout << "Moving Up" << std::endl;
							AISnake.S_Direction = AISnake.Up;
						}
					}
					else
					{
						std::cout << "Moving Y" << std::endl;
						if (YDir > 0 && AISnake.S_Direction != AISnake.Down)
						{
							AISnake.S_Direction = AISnake.Up;
							std::cout << "Moving -Y" << std::endl;
						}
						else if (YDir < 0 && AISnake.S_Direction != AISnake.Up)
						{
							AISnake.S_Direction = AISnake.Down;
							std::cout << "Moving +Y" << std::endl;
						}
						else
						{
							AISnake.S_Direction = AISnake.Right;
						}
					}
				}
				else if (AISnake.Breath <= 35)
				{
					std::cout << "Low breath!" << std::endl;
					if (AISnake.S_Direction != AISnake.Down && AISnake.Segments.front().y > G_SeaLevel - 20)
					{
						std::cout << "Moving to air!" << std::endl;
						AISnake.S_Direction = AISnake.Up;
					}
					else if (AISnake.Segments.front().y == G_SeaLevel - 20)
					{
						if (AISnake.Segments.front().x > 20 && AISnake.S_Direction != AISnake.Right)
							AISnake.S_Direction = AISnake.Left;
						else if (AISnake.Segments.front().x < 780 && AISnake.S_Direction != AISnake.Left)
							AISnake.S_Direction = AISnake.Right;
						else
							AISnake.S_Direction = AISnake.Up;
					}
					else if (AISnake.S_Direction == AISnake.Down)
					{
						std::cout << "Moving left, facing down!" << std::endl;
						AISnake.S_Direction = AISnake.Left;
					}
					else
					{
						std::cout << "Moving Down!" << std::endl;
						AISnake.S_Direction = AISnake.Down;
					}
				}
				AISnake.MoveSnake(G_SeaLevel, AISnake);

				if (PlrSnake.Segments.front().y < G_SeaLevel && PlrSnake.Breath < 100) PlrSnake.Breath += 1;
				else PlrSnake.Breath -= 1;
				if (AISnake.Segments.front().y < G_SeaLevel && AISnake.Breath < 100) AISnake.Breath += 1;
				else AISnake.Breath -= 1;

				std::cout << "PlrBreath: " << PlrSnake.Breath << std::endl;
				std::cout << "AIBreath: " << AISnake.Breath << std::endl;

				if (PlrSnake.Breath <= 0) PlrSnake.S_State = PlrSnake.Dead;
				if (AISnake.Breath <= 0) AISnake.S_State = AISnake.Dead;

				for (int i = 0; i < Collectables.size(); i++)
				{
					if (Collectables[i].Position == PlrSnake.Segments.front())
					{
						PlrSnake.Segments.PushBack(sf::Vector2f(-20, -20));
						PlrSnake.Breath += 10;
						Collectables.erase(Collectables.begin() + i);

					}
					if (Collectables[i].Position == AISnake.Segments.front()) //Vector overflow error - Exceeded number of items in the list?
					{
						AISnake.Segments.PushBack(sf::Vector2f(-40, -40));
						AISnake.Breath += 10;
						Collectables.erase(Collectables.begin() + i);
					}
				}
				for (int i = 0; i < PlrSnake.Segments.Size(); i++)
				{
					if (PlrSnake.Segments.GetAt(i) != PlrSnake.Segments.front())
					{
						if (PlrSnake.Segments.front().x == PlrSnake.Segments.GetAt(i).x && PlrSnake.Segments.front().y == PlrSnake.Segments.GetAt(i).y)
							return;
					}
				}
				UpdateClock.restart();

				if (rand() % 6 == 2 && Collectables.size() < 5)
				{
					Collectable NewCollectable;
					NewCollectable.Position = sf::Vector2f(-1, -1);
					do { NewCollectable.Position = FindFreePosition(); } while (NewCollectable.Position == sf::Vector2f(-1, -1));

					//NewCollectable.Position = sf::Vector2f(rand() % (760 / 20) * 20 + 20, rand() % (760 / 20) * 20 + 20);
					Collectables.push_back(NewCollectable);
				}
			}
			else
			{
				
				if (PlrSnake.S_State == PlrSnake.Dead)
				{
					std::cout << "Watery grave..." << std::endl;
					std::cout << "The snake couldn't 'sea' anymore..." << std::endl;
					std::cout << "You lost with: " << PlrSnake.Segments.Size() << " points!" << std::endl;
				}
				else
				{
					std::cout << "Watery grave..." << std::endl;
					std::cout << "The snake couldn't 'sea' anymore..." << std::endl;
					std::cout << "You won with: " << PlrSnake.Segments.Size() << " points!" << std::endl;
				}

				return;
			}
		}
		GraphicsWindow.clear(); //Clearing the graphics window before rendering more.

		for (Collectable i : Collectables)
			i.SpawnCollectable(GraphicsWindow);

		PlrSnake.DrawSnake(GraphicsWindow); //Calling the draw function in Snake.CPP
		AISnake.DrawSnake(GraphicsWindow);
		GraphicsWindow.draw(Water);

		//Draw the water

		GraphicsWindow.display(); //Display output. Though this is self explanatory.
	}
	return;
}
sf::Vector2f Game::FindFreePosition()
{
	sf::Vector2f Pos;
	Pos.x = rand() % (760 / 20) * 20 + 20;
	Pos.y = rand() % 800 - ((G_SeaLevel / 20) * 20);

	std::cout << Pos.y << std::endl;
	std::cout << G_SeaLevel;

	//Height * 40
	//CellSize * Num of Cells = max

	for (int i = 0; i < Collectables.size(); i++)
	{
		if (Collectables[i].Position == Pos && Collectables[i].Position != sf::Vector2f(-1, -1))
		{
			return sf::Vector2f(-1, -1);
		}
	}
	return Pos;
}