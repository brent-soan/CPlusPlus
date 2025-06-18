#include <SFML/Window.hpp>
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

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			square.move({ 0.0f, -0.1f });
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			square.move({ -0.1f, 0.0f });
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			square.move({ 0.0f, 0.1f });
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			square.move({ 0.1f, 0.0f });
		}

		window.clear(sf::Color::Blue);
		window.draw(square);
		window.display();
	}
}