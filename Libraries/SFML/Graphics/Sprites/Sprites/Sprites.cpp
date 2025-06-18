#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");

	sf::Texture texture("Textures/RAHHH.jpg");
	//sf::Texture texture("Textures/RAHHH.jpg", false, { { 0, 0 }, { 32, 32 } });
	
	sf::Sprite sprite(texture);
	//sprite.setColor(sf::Color::Blue);

	while(window.isOpen()) {
		while(const auto event = window.pollEvent()) {
			if(event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}
}