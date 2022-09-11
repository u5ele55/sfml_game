#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "../graphics/texture_manager.hpp"
#include "../objects/player.hpp"

#include <iostream>

int GameCore::execute() {
	
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
	Graphics::TextureManager& textureManager = Graphics::TextureManager::getInstance();
	window.setKeyRepeatEnabled(false);
	Objects::Player a;
	sf::Clock clock;

	while (window.isOpen())
	{
	    sf::Event event;
	    while (window.pollEvent(event))
	    {
	        if (event.type == sf::Event::Closed)
	            window.close();
			a.onEvent(event);
	    }
		sf::Time elapsedTime = clock.restart();
		a.onUpdate(elapsedTime);
	    window.clear();
	    window.draw(a.sprite());
	    window.display();
	}

	return 0;
}

