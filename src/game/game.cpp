#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "../graphics/texture_manager.hpp"

#include <iostream>

int GameCore::execute() {
	
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
	Graphics::TextureManager& textureManager = Graphics::TextureManager::getInstance();

	Object a = Object(Graphics::Tile);

	a.sprite().setTextureRect(sf::IntRect(64*3, 64*4, 64, 64));

	while (window.isOpen())
	{
	    sf::Event event;
	    while (window.pollEvent(event))
	    {
	        if (event.type == sf::Event::Closed)
	            window.close();
	    }
	    window.clear();
	    window.draw(a.sprite());
	    window.display();
	}

	return 0;
}

