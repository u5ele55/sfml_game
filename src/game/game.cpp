#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "../objects/player.hpp"
#include "../map/cell.hpp"
#include "level_painter.hpp"
#include <iostream>

int GameCore::execute() {
	
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
	window.setKeyRepeatEnabled(false);
	
	sf::Clock clock;
	m_playerIndex = 0;
	Objects::Player player;
	m_creatures.push_back(player);
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
		LevelPainter::drawWindow(window, m_creatures);
	    
	}

	return 0;
}

void GameCore::updateScene(const sf::Time &elapsedTime) {
	for (auto creature : m_creatures) {
		bool canGo = creature.increaseStepPhase(elapsedTime.asSeconds());
		// Pass creature to CreatureController, that will change its charasteristics
	}

}

void GameCore::onEvent(const sf::Event &event) {
	if (event.type == sf::Event::KeyPressed) {
		bool wantToGo = false;
		if (event.key.code == sf::Keyboard::W) {
			m_creatures[m_playerIndex].setFacing(Objects::Direction::UP);
			wantToGo = true;
		} 
		else if (event.key.code == sf::Keyboard::A) {
			m_creatures[m_playerIndex].setFacing(Objects::Direction::LEFT);
			wantToGo = true;
		} 
		else if (event.key.code == sf::Keyboard::S) {
			m_creatures[m_playerIndex].setFacing(Objects::Direction::DOWN);
			wantToGo = true;
		} 
		else if (event.key.code == sf::Keyboard::D) {

	std::cout << "before setFacing\n";
			m_creatures[m_playerIndex].setFacing(Objects::Direction::RIGHT);
			
	std::cout << "after setFacing\n";
			wantToGo = true;
		}
		if (wantToGo && m_creatures[m_playerIndex].canGo()) {
			auto facing = m_creatures[m_playerIndex].getFacing();
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
	std::cout << "after ifs and switch\n";

			m_creatures[m_playerIndex].makeStep();
	std::cout << "after makeStep\n";
			auto oldPos = m_creatures[m_playerIndex].getPosition();

	std::cout << "after getPosition\n";
			m_creatures[m_playerIndex].setPosition(oldPos + move);
	std::cout << "after setPosition\n";
		}
	}
}