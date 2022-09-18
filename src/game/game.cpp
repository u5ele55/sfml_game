
#include "game.hpp"
#include "../objects/player.hpp"
#include "../map/cell.hpp"
#include "../graphics/level_painter.hpp"
#include "event_reader.hpp"
#include <iostream>

GameCore::GameCore(GameMediator *notifier) : m_notifier(notifier), m_playerPosition({1,1}) {
	m_window = new sf::RenderWindow(sf::VideoMode(1280, 960), "SFML works!");
}

int GameCore::execute() {
	
	sf::Clock clock;

	m_map = Map::FieldMap(20, 15);

	while (m_window->isOpen())
	{
		
		sf::Time elapsedTime = clock.restart();

	    m_notifier->callReader(m_window);
		updateScene(elapsedTime);
		Graphics::LevelPainter::drawWindow(*m_window, m_playerPosition, m_player, m_objects, m_map);
	    
	}

	return 0;
}

void GameCore::updateScene(const sf::Time &elapsedTime) {
	m_player.increaseStepPhase(elapsedTime.asSeconds());
	for (auto &creature : m_creatures) {
		bool canGo = creature.increaseStepPhase(elapsedTime.asSeconds());
		// Pass creature to CreatureController, that will return creature event
	}
}

void GameCore::onEvent(const UserEvent &event) {
	bool wantToGo = false;
	auto prevFacing = m_player.getFacing();
	if (event == UserEvent::UP) {
		m_player.setFacing(Objects::Direction::UP);
		wantToGo = true;
	} 
	else if (event == UserEvent::LEFT) {
		m_player.setFacing(Objects::Direction::LEFT);
		wantToGo = true;
	} 
	else if (event == UserEvent::DOWN) {
		m_player.setFacing(Objects::Direction::DOWN);
		wantToGo = true;
	} 
	else if (event == UserEvent::RIGHT) {
		m_player.setFacing(Objects::Direction::RIGHT);
		wantToGo = true;
	}
	else if (event == UserEvent::ESC) {
		closeWindow();
		return;
	}
	
	if (wantToGo && m_player.canGo() && prevFacing == m_player.getFacing()) {
		auto facing = m_player.getFacing();
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
		
		const Common::Vector2D<int> &cellCoords = m_map.getCoords(m_playerPosition + move);
		if (!m_map.getCellSolidity(cellCoords)) {
			// if it's not solid, then go
			m_playerPosition += move;
			m_player.makeStep();
			m_map.triggerCellEvent(cellCoords);
		}
	
	}
}

void GameCore::closeWindow() {m_window->close();}