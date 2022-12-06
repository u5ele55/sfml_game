
#include "game.hpp"
#include "../objects/player.hpp"
#include "../map/cell.hpp"
#include "../graphics/level_painter.hpp"
#include "../graphics/dialogs/choose_map_dialog.hpp"

#include "../map/events/change_cell_event.hpp"
#include "../map/events/damage_player_event.hpp"
#include "../map/events/lose_event.hpp"
#include "../map/events/win_event.hpp"
#include "../map/events/change_map_event.hpp"
#include "../map/events/player_speed_multiplier_event.hpp"
#include "../map/events/player_heal_event.hpp"

#include "../map/generation/map_generator.hpp"
#include "../map/generation/rules/obstacles_rule.hpp"
#include "../map/generation/rules/field_size_rule.hpp"
#include "../map/generation/rules/player_position_rule.hpp"
#include "../map/generation/rules/win_position_rule.hpp"
#include "../map/generation/rules/damage_event_frequency_rule.hpp"

#include "../map/save/save_file_loader.hpp"
#include "../map/save/file_map_saver.hpp"

#include "../log/console_logger.hpp"
#include "../log/logger_pool.hpp"
#include "../log/messages/player_messages.hpp"
#include "../log/messages/game_states_messages.hpp"


#include <iostream>

GameCore::GameCore(GameMediator *notifier)
	: m_notifier(notifier)
	  {}

void GameCore::start() {
	notify(Log::GameStateMessages::gameStarted());

	configureField();

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
		lvlPainter.drawWindow(*m_map.player, m_objects, m_map);
	    
	}
	delete m_window;
	m_notifier->gameEnded();
}

void GameCore::updateScene(const sf::Time &elapsedTime) {
	m_map.player->creature.increaseStepPhase(elapsedTime.asSeconds());

	if (!m_map.player->creature.isAlive())
		*m_map.state = GameState::LOSS;

	if (*m_map.state == GameState::WIN) {
		notify(Log::GameStateMessages::win());
		closeWindow();
	} 
	else if (*m_map.state == GameState::LOSS) {
		notify(Log::GameStateMessages::lose());
		closeWindow();
	}
	
}

void GameCore::onEvent(const UserEvent &event) {
	bool wantToGo = false;
	auto prevFacing = m_map.player->creature.getFacing();
	
	switch (event)
	{
	case UserEvent::UP:
		m_map.player->creature.setFacing(Objects::Direction::UP);
		wantToGo = true;
		break;
	case UserEvent::LEFT:
		m_map.player->creature.setFacing(Objects::Direction::LEFT);
		wantToGo = true;
		break;
	case UserEvent::DOWN:
		m_map.player->creature.setFacing(Objects::Direction::DOWN);
		wantToGo = true;
		break;
	case UserEvent::RIGHT:
		m_map.player->creature.setFacing(Objects::Direction::RIGHT);
		wantToGo = true;
		break;
	case UserEvent::USE:
		break;
	case UserEvent::SAVE_GAME:
		saveMapProcess();
		break;
	case UserEvent::LOAD_GAME:
		loadMapProcess();
		break;
	case UserEvent::ESC:
		closeWindow();
		break;
	default:
		break;
	}
	
	if (wantToGo && m_map.player->creature.canGo() && prevFacing == m_map.player->creature.getFacing()) {
		const auto &facing = m_map.player->creature.getFacing();
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
		
		const auto &cellCoords = m_map.getCoords(m_map.player->position + move);
		
		if (!m_map.getCellSolidity(cellCoords)) {
			m_map.player->position = cellCoords;
			m_map.player->creature.makeStep();
			m_map.triggerCellEvent(cellCoords);
			
       		notify(Log::PlayerMessages::changedPosition(cellCoords));
		} else {
        	notify(Log::PlayerMessages::triesToPassSolidCell(cellCoords));
		}
	}
}

void GameCore::configureField() {

	char fieldLoadingChoice = '\0';
	while (!fieldLoadingChoice) {
		std::cout << "Enter 's' if you want to start from save: ";
	
		std::cin >> fieldLoadingChoice;
		if (fieldLoadingChoice == 's') {
			loadMapProcess(&fieldLoadingChoice);
		}
	}
	if (fieldLoadingChoice == 's') return;

	Graphics::ChooseMapDialog chooseDialog;
	Map::MapType mapType = chooseDialog.showDialog();
	notify(Log::GameStateMessages::mapChoosen());
	try {
		if (mapType == Map::MapType::Dungeon) {
			Map::MapGenerator<
				Map::ObstaclesRule<Map::ObstaclesVariant::ROOMS>,
				Map::FieldSizeRule<6,6>,
				Map::WinEventPositionRule<-3,-2>,
				Map::DamageEventFrequencyRule<100, 5>,
				Map::PlayerPositionRule<1,1>
				> mg;
			m_map = mg.generate(); 
		}
		else if (mapType == Map::MapType::Overworld) {
			Map::MapGenerator<
				Map::ObstaclesRule<Map::ObstaclesVariant::SPIRAL>,
				Map::FieldSizeRule<8,12>, 
				Map::WinEventPositionRule<(8-1)/2,12/2>,
				Map::PlayerPositionRule<1,1>
				> mg; 
			m_map = mg.generate();
		}
	} catch(std::invalid_argument e) {
		notify(Log::GameStateMessages::errorOnMapChoice(e.what()));
		return;
	} catch (...) {
        notify(Log::GameStateMessages::wrongMapChoice());
		return;
	}
}

void GameCore::saveMapProcess() {
	Map::FileMapSaver saver;
	std::string name;
	std::cout << "Enter the name of the save: ";
	std::cin >> name;
	saver.saveMap(m_map, name);
}

void GameCore::loadMapProcess(char *choice) {
	std::string filename;
	std::cout << "Enter the name of the file with the save: ";
	std::cin >> filename;
	try {
		Map::SaveFileLoader loader(filename);
		m_map = loader.loadMap();
	} catch (const Exceptions::LoadingMapException& exc) {
		notify(Log::Message(Log::LogType::CriticalState, exc.what()));
		if (choice != nullptr) *choice = '\0';
	}
}

void GameCore::closeWindow() {
	m_window->close();
	notify(Log::GameStateMessages::windowClosed());
}
