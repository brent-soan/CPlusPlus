#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");

	sf::Font font("Fonts/Allura-Regular.ttf");
	sf::Text text(font);
	text.setString("Hello, SFML!");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);

	while(window.isOpen()) {
		while(const auto event = window.pollEvent()) {
			if(event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		window.clear(sf::Color::White);
		window.draw(text);
		window.display();
	}
}