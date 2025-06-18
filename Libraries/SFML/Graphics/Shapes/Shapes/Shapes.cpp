#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");

	sf::RectangleShape square1({ 100.0f, 100.0f });
	square1.setPosition({ 250.0f, 250.0f });
	sf::Texture texture1("Textures/my-notion-face-portrait.png");
	square1.setTexture(&texture1);

	sf::RectangleShape square2({ 100.0f, 100.0f });
	square2.setPosition({ 400.0f, 250.0f });
	sf::Texture texture2("Textures/my-notion-face-transparent.png");
	square2.setTexture(&texture2);

	while(window.isOpen()) {
		while(const auto event = window.pollEvent()) {
			if(event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		window.clear();
		window.draw(square1);
		window.draw(square2);
		window.display();
	}
}