#include "choose_map_dialog.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../sprite_manager.hpp"

namespace Graphics
{
		
	ChooseMapDialog::ChooseMapDialog() {
		SpriteManager &spriteManager = SpriteManager::getInstance();
		
		double nextY = 0, maxWidth = 0;
		for (auto &type : Map::existingMapTypes) {
			MapTypeButton btn = {spriteManager.getMapButtonSprite(type), type};
			btn.sprite.setPosition(0, nextY);
			nextY += btn.sprite.getLocalBounds().height;
			maxWidth = maxWidth > btn.sprite.getLocalBounds().width ? maxWidth : btn.sprite.getLocalBounds().width;
			m_buttons.push_back(btn);
		}
		m_height = nextY;
		m_width = maxWidth;
	}

	Map::MapType ChooseMapDialog::showDialog() {
		sf::RenderWindow window(sf::VideoMode(m_width, m_height), "Choose your map", sf::Style::Close);

		Map::MapType res = Map::MapType::Dungeon;
		bool notClosed = true;

		while(window.isOpen() && notClosed) {
			sf::Event event;
			while(window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					notClosed = false;
				}
				// Handle btn taps
				if (event.type == sf::Event::MouseButtonPressed) {
					const auto &pos = sf::Mouse::getPosition(window);
					//std::cout << pos.x << ' ' << pos.y << '\n';

					for(const MapTypeButton &btn : m_buttons) {
						const auto& rect = btn.sprite.getGlobalBounds();
						if (rect.contains(pos.x, pos.y)) {
							res = btn.type;
							notClosed = false;
							break;
						}
					}
				}
			}

			window.clear();
			for(const MapTypeButton &btn : m_buttons)
				window.draw(btn.sprite);
			
			window.display();
		}
		
		window.close();

		return res;
	}
} // namespace Graphics
