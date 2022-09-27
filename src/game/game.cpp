
#include "game.hpp"
#include "../objects/player.hpp"
#include "../map/cell.hpp"
#include "../graphics/level_painter.hpp"
#include "event_reader.hpp"
#include "../graphics/dialogs/choose_map_dialog.hpp"

#include "../map/events/change_cell_event.hpp"
#include "../map/events/damage_player_event.hpp"
#include "../map/events/lose_event.hpp"
#include "../map/events/win_event.hpp"
#include "../map/events/change_map_event.hpp"
#include "../map/events/player_speed_multiplier_event.hpp"

#include <iostream>

GameCore::GameCore(GameMediator *notifier)
	: m_notifier(notifier), 
	  m_player(Common::Vector2D<int>{1,1}, Objects::Player()),
	  m_state(GameState::PLAYING)
	  {}

void GameCore::start() {

	Graphics::ChooseMapDialog chooseDialog;
	Map::MapType mapType = chooseDialog.showDialog();

	switch (mapType) {
	// Later: delegate map generation to some map generator
	case Map::MapType::Dungeon:
		m_map = Map::FieldMap(10,10);
		break;
	case Map::MapType::Overworld:
		m_map = Map::FieldMap(15,15);
		break;
	default:
		break;
	}

	setMapEvents();

	m_window = new sf::RenderWindow(
		sf::VideoMode(Graphics::WINDOW_WIDTH, Graphics::WINDOW_HEIGHT), "LitterBox", sf::Style::Close
		);
	Graphics::LevelPainter lvlPainter(*m_window);

	sf::Clock clock;
	while (m_window->isOpen())
	{
		
		sf::Time elapsedTime = clock.restart();

	    m_notifier->callReader(m_window);
		updateScene(elapsedTime);
		lvlPainter.drawWindow(m_player, m_objects, m_map);
	    
	}
}

void GameCore::updateScene(const sf::Time &elapsedTime) {
	m_player.creature.increaseStepPhase(elapsedTime.asSeconds());

	if (m_player.creature.getHp() <= 0)
		m_state = GameState::LOSS;

	if (m_state == GameState::WIN) {
		std::cout << "You win!\n";
		closeWindow();
	} 
	else if (m_state == GameState::LOSS) {
		std::cout << "Loser!\n";
		closeWindow();
	}
}

void GameCore::onEvent(const UserEvent &event) {
	bool wantToGo = false;
	auto prevFacing = m_player.creature.getFacing();
	switch (event)
	{
	case UserEvent::UP:
		m_player.creature.setFacing(Objects::Direction::UP);
		wantToGo = true;
		break;
	case UserEvent::LEFT:
		m_player.creature.setFacing(Objects::Direction::LEFT);
		wantToGo = true;
		break;
	case UserEvent::DOWN:
		m_player.creature.setFacing(Objects::Direction::DOWN);
		wantToGo = true;
		break;
	case UserEvent::RIGHT:
		m_player.creature.setFacing(Objects::Direction::RIGHT);
		wantToGo = true;
		break;
	case UserEvent::USE:
		break;
	case UserEvent::ESC:
		closeWindow();
		break;
	default:
		break;
	}
	
	if (wantToGo && m_player.creature.canGo() && prevFacing == m_player.creature.getFacing()) {
		const auto &facing = m_player.creature.getFacing();
		Common::Vector2D<int> move{0,0};
		
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
		
		const auto &cellCoords = m_map.getCoords(m_player.position + move);

		if (!m_map.getCellSolidity(cellCoords)) {
			// if it's not solid, then go
			m_player.position = cellCoords;
			m_player.creature.makeStep();
			m_map.triggerCellEvent(cellCoords);
		}
	}
}

void GameCore::closeWindow() {
	m_window->close();
	std::cout << "Window closed\n";
}

void GameCore::setMapEvents() {
	Map::Cell *a = new Map::Cell(Map::TileType::GRASS);
	Map::Cell b = Map::Cell(Map::TileType::STONE, true);
	std::vector<Map::Events::CellData> data = {
		{{2,1}, b},
		{{2,3}, b},
		{{3,1}, b},
		{{3,3}, b},
		{{1,2}, b},
		{{4,2}, b},
		{{2,2}, Map::Cell(Map::TileType::DIRT)}
	};

	a->setEvent(new Map::Events::ChangeCellsEvent(m_map, data));
	m_map.setCell({2,2}, *a);

	Map::Cell *c = new Map::Cell(Map::TileType::DIRT);
	c->setEvent(new Map::Events::DamagePlayerEvent(m_player, 20));
	m_map.setCell({3,2}, *c);

	Map::Cell *d = new Map::Cell(Map::TileType::STONE);
	d->setEvent(new Map::Events::ChangeMapEvent(m_player, {1,1}, m_map, Map::FieldMap(12,12)));
	m_map.setCell({3,4}, *d);

	Map::Cell *w = new Map::Cell(Map::TileType::DIRT);
	w->setEvent(new Map::Events::WinStateEvent(m_state));
	m_map.setCell({-1,-1}, *w);
}