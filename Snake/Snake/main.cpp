#include <SFML/Graphics.hpp>

int main()
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

		sf::ConvexShape polygon;

		polygon.setPointCount(5);
		polygon.setPoint(0, sf::Vector2f(0, 0));
		polygon.setPoint(1, sf::Vector2f(150, 10));
		polygon.setPoint(2, sf::Vector2f(150, 150));
		polygon.setPoint(3, sf::Vector2f(75, 200));
		polygon.setPoint(4, sf::Vector2f(0, 150));

		polygon.setFillColor(sf::Color::Blue);
		polygon.setPosition({ 50, 50 });

		sf::CircleShape Circle;

		Circle.setRadius(50);
		Circle.setOutlineColor(sf::Color::White);
		Circle.setFillColor(sf::Color::Transparent);
		Circle.setOutlineThickness(8);
		Circle.setPosition({ 75, 80 });

		sf::RectangleShape Rectangle;

		Rectangle.setFillColor(sf::Color::Green);
		Rectangle.setOutlineColor(sf::Color::Magenta);
		Rectangle.setOutlineThickness(15);
		Rectangle.setPosition({ 106, 108});
		Rectangle.setSize(sf::Vector2f(40, 40));

		sf::Text NewText(font);
		NewText.setString("Hello, World!");
		NewText.setCharacterSize(16);

		GraphicsWindow.clear();
		GraphicsWindow.draw(polygon);
		GraphicsWindow.draw(Circle);
		GraphicsWindow.draw(Rectangle);
		GraphicsWindow.draw(NewText);
		GraphicsWindow.display();

	}

	return 0;
};