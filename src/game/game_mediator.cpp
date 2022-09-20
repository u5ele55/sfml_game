#include "game_mediator.hpp"

#include <iostream>

GameMediator::GameMediator() {
    m_eventReader = new SfmlEventReader(this);
    m_game = new GameCore(this);
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
