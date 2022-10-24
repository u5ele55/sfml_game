#ifndef GAME_MEDIATOR_HPP
#define GAME_MEDIATOR_HPP

class GameMediator;

#include "sfml_event_reader.hpp"
#include "controls/user_event.hpp"
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
    SfmlEventReader *m_eventReader;

    void configureLogging();
};

#endif