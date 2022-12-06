#ifndef GAME_HPP
#define GAME_HPP

class GameCore;

#include <vector>
#include <SFML/Graphics.hpp>
#include "../objects/object.hpp"
#include "../map/map.hpp"
#include "game_mediator.hpp"
#include "game_state.hpp"
#include "../log/observable.hpp"

class GameCore : public Log::Observable {
public:
	GameCore(GameMediator *notifier);
	void start();
	void onEvent(const UserEvent &);
private:
	void closeWindow();
	void updateScene(const sf::Time&);

	void configureField();
	void saveMapProcess();
	void loadMapProcess(char *choice = nullptr);

	sf::RenderWindow *m_window;

	std::vector<Objects::Object> m_objects;
	Map::FieldMap m_map;
	
	GameMediator *m_notifier;
};

#endif