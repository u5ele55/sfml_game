
#include "game.hpp"
#include "../objects/player.hpp"
#include "../map/cell.hpp"
#include "../graphics/level_painter.hpp"
#include "event_reader.hpp"
#include <iostream>

GameCore::GameCore(GameMediator *notifier) : m_notifier(notifier) {
	m_window = new sf::RenderWindow(sf::VideoMode(1280, 960), "SFML works!");
}

int GameCore::execute() {
	
	sf::Clock clock;
	
	m_playerIndex = 0;
	Objects::Player player;
	m_creatures.push_back(player);

	m_map = Map::FieldMap(20, 15);

	while (m_window->isOpen())
	{
		
		sf::Time elapsedTime = clock.restart();

	    m_notifier->callReader(m_window);
		updateScene(elapsedTime);

		Graphics::LevelPainter::drawWindow(*m_window, m_creatures, m_playerIndex, m_objects, m_map);
	    
	}

	return 0;
}

void GameCore::updateScene(const sf::Time &elapsedTime) {
	for (auto &creature : m_creatures) {
		bool canGo = creature.increaseStepPhase(elapsedTime.asSeconds());
		// Pass creature to CreatureController, that will return creature event
	}
}

void GameCore::onEvent(const UserEvent &event) {
	auto &player = m_creatures[m_playerIndex];
	
	bool wantToGo = false;
	auto prevFacing = player.getFacing();
	if (event == UserEvent::UP) {
		player.setFacing(Objects::Direction::UP);
		wantToGo = true;
	} 
	else if (event == UserEvent::LEFT) {
		player.setFacing(Objects::Direction::LEFT);
		wantToGo = true;
	} 
	else if (event == UserEvent::DOWN) {
		player.setFacing(Objects::Direction::DOWN);
		wantToGo = true;
	} 
	else if (event == UserEvent::RIGHT) {
		player.setFacing(Objects::Direction::RIGHT);
		wantToGo = true;
	}
	else if (event == UserEvent::ESC) {
		closeWindow();
		return;
	}
	
	if (wantToGo && player.canGo() && prevFacing == player.getFacing()) {
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
		const Map::Cell *cell = m_map.get(oldPos + move);
		if (!cell->getSolidity()) {
			// if it's not solid, then go
			player.setPosition(cell->getPosition());
			player.makeStep();
			m_map.get(oldPos + move)->triggerEvent();
		}
	
	}
}

void GameCore::closeWindow() {m_window->close();}