#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");
	sf::RectangleShape square({ 100.0f, 100.0f });
	square.setFillColor(sf::Color::Red);

	while(window.isOpen()) {
		while(const auto event = window.pollEvent()) {
			if(event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		window.clear(sf::Color::Blue);
		window.draw(square);
		window.display();
	}
}