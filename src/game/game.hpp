#ifndef GAME_HPP
#define GAME_HPP

class GameCore;

#include <vector>
#include <SFML/Graphics.hpp>
#include "../objects/object.hpp"
#include "../common/creature_wrapper.hpp"
#include "../map/map.hpp"
#include "game_mediator.hpp"
#include "game_state.hpp"

class GameCore {
public:
	GameCore(GameMediator *notifier);
	void start();
	void onEvent(const UserEvent &);
private:
	void closeWindow();
	void updateScene(const sf::Time&);
	void setMapEvents();

	sf::RenderWindow *m_window;

	std::vector<Objects::Object> m_objects;
	Map::FieldMap m_map;
	Common::CreatureWrapper m_player;
	
	GameMediator *m_notifier;

	GameState m_state;
};

#endif