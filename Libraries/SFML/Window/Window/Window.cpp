#include <SFML/Window.hpp>

int main()
{
	//sf::Window window(sf::VideoMode({ 800, 600 }), "My window");
	sf::Window window;
	window.create(sf::VideoMode({ 800, 600 }), "Sample window title");
	window.setSize({ 1920, 1080 });
	window.setTitle("Sample window title 2");
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}
	}
}