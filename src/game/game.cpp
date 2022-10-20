
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
#include "../map/events/player_heal_event.hpp"

#include "../log/console_logger.hpp"

#include <iostream>

GameCore::GameCore(GameMediator *notifier)
	: m_notifier(notifier), 
	  m_player(Common::Vector2D<int>{1,1}, Objects::Player()),
	  m_state(GameState::PLAYING)
	  {}

void GameCore::start() {
	notify(Log::Message(Log::LogType::GameState, "Game started"));
	Graphics::ChooseMapDialog chooseDialog;
	Map::MapType mapType = chooseDialog.showDialog();
	notify(Log::Message(Log::LogType::GameState, "Map choosen"));
	try {
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
	} catch(std::invalid_argument e) {
		notify(Log::Message(Log::LogType::CriticalState, e.what()));
		return;
	} catch (...) {
        notify(Log::Message(Log::LogType::CriticalState, "Wrong map choice"));
		return;
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
	delete m_window;
	m_notifier->gameEnded();
}

void GameCore::updateScene(const sf::Time &elapsedTime) {
	m_player.creature.increaseStepPhase(elapsedTime.asSeconds());

	if (!m_player.creature.isAlive())
		m_state = GameState::LOSS;

	if (m_state == GameState::WIN) {
		notify(Log::Message(Log::LogType::GameState, "Win!"));
		closeWindow();
	} 
	else if (m_state == GameState::LOSS) {
		notify(Log::Message(Log::LogType::GameState, "Loss!"));
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
		std::string x = std::to_string(cellCoords.x),
					y = std::to_string(cellCoords.y);
		std::string pos = "["+x+", "+y+"]";

		if (!m_map.getCellSolidity(cellCoords)) {
			m_player.position = cellCoords;
			m_player.creature.makeStep();
			m_map.triggerCellEvent(cellCoords);
			
       		notify(Log::Message(Log::LogType::ObjectState, "Player position : "+pos));
		} else {
        	notify(Log::Message(Log::LogType::CriticalState, "Player tries to pass through solid cell " + pos));
		}
	}
}

void GameCore::closeWindow() {
	m_window->close();
	notify(Log::Message(Log::LogType::GameState, "Window closed"));
}

void GameCore::setMapEvents() {
	Map::Events::Event *ev;

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
	ev = new Map::Events::ChangeCellsEvent(m_map, data); ev->copySubscriptions(this);
	m_map.setCellEvent({2,2}, ev);
	ev = new Map::Events::DamagePlayerEvent(m_player, 20); ev->copySubscriptions(this);
	m_map.setCellEvent({3,2}, ev);
	
	Map::FieldMap newMap = Map::FieldMap(6,8);
	Map::Cell d = Map::Cell(Map::TileType::STONE);

	newMap.setCell({3,3}, d);
	ev = new Map::Events::PlayerSpeedMultiplierEvent(m_player, 2); ev->copySubscriptions(this);
	newMap.setCellEvent({3,3}, ev);

	ev = new Map::Events::ChangeMapEvent(m_player, {1,2}, m_map, newMap); ev->copySubscriptions(this);
	m_map.setCellEvent({3,4}, ev);
	
	m_map.setCell({4,4}, Map::Cell(Map::TileType::GRASS));
	ev = new Map::Events::PlayerSpeedMultiplierEvent(m_player, 2); ev->copySubscriptions(this);
	m_map.setCellEvent({4,4}, ev);


	m_map.setCell(-2, -1, Map::Cell(Map::TileType::STONE, true));
	m_map.setCell(-1, -2, Map::Cell(Map::TileType::STONE, true));
	m_map.setCell( 0, -1, Map::Cell(Map::TileType::STONE, true));
	m_map.setCell(-1,  0, Map::Cell(Map::TileType::STONE, true));

	std::vector<Map::Events::CellData> data_gates = {
		{{-2, -1}, Map::Cell(Map::TileType::GRASS)},
		{{-1, -2}, Map::Cell(Map::TileType::GRASS)},
		{{ 0, -1}, Map::Cell(Map::TileType::GRASS)},
		{{-1,  0}, Map::Cell(Map::TileType::GRASS)},
	};

	for (auto cellData : data_gates) {
		Map::Cell cell = cellData.cell;
		cell.setSolidity(true);
		cell.setTileType(Map::TileType::STONE);
		m_map.setCell(cellData.position, cell);
	}

	Map::Cell m = Map::Cell(Map::TileType::GRASS);
	ev = new Map::Events::ChangeCellsEvent(m_map, data_gates);
	ev->copySubscriptions(this);
	m.setEvent(ev);
	m_map.setCell({4,6}, m);

	Map::Cell w = Map::Cell(Map::TileType::DIRT);
	ev = new Map::Events::WinStateEvent(m_state);
	ev->copySubscriptions(this);
	w.setEvent(ev);
	m_map.setCell({-1,-1}, w);
}