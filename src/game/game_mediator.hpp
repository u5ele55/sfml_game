#ifndef GAME_MEDIATOR_HPP
#define GAME_MEDIATOR_HPP

class GameMediator;
enum UserEvent {
    NONE, ESC, RIGHT, LEFT, UP, DOWN, USE
};

#include "event_reader.hpp"
#include "game.hpp"

class GameMediator {
public:
    GameMediator();
    void notify(UserEvent event);
    void callReader(sf::RenderWindow *);
    void startGame();

    ~GameMediator();
private:
    GameCore *m_game;
    SfmlEventReader *m_eventReader;
};

#endif