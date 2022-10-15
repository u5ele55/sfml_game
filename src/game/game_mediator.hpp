#ifndef GAME_MEDIATOR_HPP
#define GAME_MEDIATOR_HPP

class GameMediator;
enum class UserEvent {
    NONE, ESC, RIGHT, LEFT, UP, DOWN, USE
};

#include "event_reader.hpp"
#include "game.hpp"
#include "../log/logger.hpp"
#include <vector>

class GameMediator {
public:
    GameMediator();
    ~GameMediator();
    void notify(UserEvent event);
    void callReader(sf::RenderWindow *);
    void startGame();
    void gameEnded();
private:
    GameCore *m_game;
    SfmlEventReader *m_eventReader;
    std::vector<Log::Logger*> m_loggers;
};

#endif