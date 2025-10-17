#include "Animation.h"
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Test");
    tgui::Gui gui(window);

    sf::Texture mainPanelTexture = sf::Texture("Assets/Frames/Writing/1.png");
    sf::Sprite mainPanelSprite(mainPanelTexture);
    mainPanelSprite.setScale({ 0.66f, 0.66f });
	Animation mainPanelAnimation(mainPanelTexture, "Assets/Frames/Writing/", 20, 0.01f);

	float deltaTime = 0.0f;
    sf::Clock clock;

    while(window.isOpen()) {
		deltaTime = clock.restart().asSeconds();

        while(const std::optional event = window.pollEvent()) {
            if(event->is<sf::Event::Closed>()) {
                window.close();
            }

            gui.handleEvent(*event);
        }

        window.clear();
		mainPanelAnimation.update(deltaTime);
        window.draw(mainPanelSprite);
        gui.draw();
        window.display();
    }

    return 0;
}