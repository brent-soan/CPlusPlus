#include <SFML/Window.hpp>
#include <iostream>

int main()
{
	sf::Window window(sf::VideoMode({ 800, 600 }), "My window");

	while (window.isOpen())
	{
		while (const auto event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>()) {
				std::cout << "Window closed\n";
				window.close();
			}

			// - Declares resized variable and initialize with value of event->getIf<sf::Event::Resized>()
			// - Code inside if block will only execute if value is of type sf::Event::Resized and not nullptr
			// - resized variable is only valid inside the if block
			if (const auto* resized = event->getIf<sf::Event::Resized>()) {
				std::cout << "Window resized\n";
				std::cout << "New height: " << resized->size.x << "\n";
				std::cout << "New width: " << resized->size.y << "\n";
			}

			if (const auto* textEntered = event->getIf<sf::Event::TextEntered>()) {
				if (textEntered->unicode < 128) {
					std::cout << static_cast<char>(textEntered->unicode) << "\n";
				}
			}
		}
	}
}