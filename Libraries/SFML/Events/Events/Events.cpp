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

			if (event->is<sf::Event::Resized>()) {
				std::cout << "Window resized\n";

				if (const auto* resized = event->getIf<sf::Event::Resized>()) {
					std::cout << "New height: " << resized->size.x << "\n";
					std::cout << "New width: " << resized->size.y << "\n";
				}
			}

			if (event->is<sf::Event::TextEntered>()) {
				if (const auto* textEntered = event->getIf<sf::Event::TextEntered>()) {
					if (textEntered->unicode < 128) {
						std::cout << static_cast<char>(textEntered->unicode) << "\n";
					}
				}
			}
		}
	}
}