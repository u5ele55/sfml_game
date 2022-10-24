#ifndef GAME_MEDIATOR_HPP
#define GAME_MEDIATOR_HPP

class GameMediator;

#include "controls/event_reader.hpp"
#include "controls/user_event.hpp"
#include "controls/controls_storage.hpp"
#include "game.hpp"
#include <vector>

class GameMediator {
public:
    GameMediator();
    void notify(UserEvent event);
    void callReader(sf::RenderWindow *);
    void startGame();
    void gameEnded();
private:
    GameCore *m_game;
    Controls::EventReader<sf::RenderWindow> *m_eventReader;

    void configureLogging();
};

#endif