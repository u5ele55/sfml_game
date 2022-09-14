#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "../objects/player.hpp"
#include "../map/cell.hpp"
#include "level_painter.hpp"
#include <iostream>

int GameCore::execute() {
	
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
	sf::Clock clock;
	
	m_playerIndex = 0;
	Objects::Player player;
	m_creatures.push_back(player);

	m_map = Map::FieldMap(15, 15);

	while (window.isOpen())
	{
		
	    sf::Event event;
		sf::Time elapsedTime = clock.restart();

	    while (window.pollEvent(event))
	    {
	        if (event.type == sf::Event::Closed)
	            window.close();
			
			onEvent(event);
	    }
		updateScene(elapsedTime);
		LevelPainter::drawWindow(window, m_creatures, m_objects, m_map);
	    
	}

	return 0;
}

void GameCore::updateScene(const sf::Time &elapsedTime) {
	for (auto &creature : m_creatures) {
		bool canGo = creature.increaseStepPhase(elapsedTime.asSeconds());
		// Pass creature to CreatureController, that will change its position
	}
}

void GameCore::onEvent(const sf::Event &event) {
	auto &player = m_creatures[m_playerIndex];

	if (event.type == sf::Event::KeyPressed) {
		bool wantToGo = false;
		if (event.key.code == sf::Keyboard::W) {
			player.setFacing(Objects::Direction::UP);
			wantToGo = true;
		} 
		else if (event.key.code == sf::Keyboard::A) {
			player.setFacing(Objects::Direction::LEFT);
			wantToGo = true;
		} 
		else if (event.key.code == sf::Keyboard::S) {
			player.setFacing(Objects::Direction::DOWN);
			wantToGo = true;
		} 
		else if (event.key.code == sf::Keyboard::D) {
			player.setFacing(Objects::Direction::RIGHT);
			wantToGo = true;
		}
		
		if (wantToGo && player.canGo()) {
			auto facing = player.getFacing();
			Common::Vector2D<int> move = {0,0};
			switch(facing) {
			case Objects::Direction::UP:
				move = {0, -1};
				break;
			case Objects::Direction::DOWN:
				move = {0, 1};
				break;
			case Objects::Direction::RIGHT:
				move = {1, 0};
				break;
			case Objects::Direction::LEFT:
				move = {-1, 0};
				break;
			}
			
			auto oldPos = player.getPosition();
			player.setPosition(oldPos + move);
			player.makeStep();
		}
	}
}