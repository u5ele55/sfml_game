#include "game_mediator.hpp"
#include "../log/console_logger.hpp"
#include "../log/file_logger.hpp"

#include <iostream>

GameMediator::GameMediator() {
    m_eventReader = new SfmlEventReader(this);
    m_game = new GameCore(this);

    auto *logger = new Log::FileLogger("log.txt");
    m_loggers.push_back(logger);
    m_game->subscribe(logger);
}

void GameMediator::startGame() { 
    m_game->start();
}

void GameMediator::gameEnded() { 
    delete m_game;
    delete m_eventReader;
}

void GameMediator::notify(UserEvent event) {
    m_game->onEvent(event);
}

void GameMediator::callReader(sf::RenderWindow *window) {
    m_eventReader->readEvent(*window);
}

GameMediator::~GameMediator() {
    for (auto *logger : m_loggers)
        delete logger;
}