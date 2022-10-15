#include "game_mediator.hpp"
#include "../log/console_logger.hpp"

#include <iostream>

GameMediator::GameMediator() {
    m_eventReader = new SfmlEventReader(this);
    m_game = new GameCore(this);

    auto *logger = new Log::ConsoleLogger;
    m_game->subscribe(logger);
}

void GameMediator::startGame() { 
    m_game->start();
}

void GameMediator::notify(UserEvent event) {
    m_game->onEvent(event);
}
void GameMediator::callReader(sf::RenderWindow *window) {
    m_eventReader->readEvent(*window);
}
