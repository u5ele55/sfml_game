#include "game_mediator.hpp"
#include "../log/console_logger.hpp"
#include "../log/file_logger.hpp"

#include <iostream>

GameMediator::GameMediator() {
    m_eventReader = new SfmlEventReader(this);
    m_game = new GameCore(this);

    // Logger pool
    // Class which stores all messages

    Log::Logger *logger = new Log::FileLogger("log.txt");
    m_loggers.push_back(logger);
    m_game->subscribe(logger);
    logger->addLogType(Log::LogType::CriticalState);
    
    Log::Logger *loggerC = new Log::ConsoleLogger;
    m_loggers.push_back(loggerC);
    m_game->subscribe(loggerC);
    loggerC->addLogType(Log::LogType::GameState);
    loggerC->addLogType(Log::LogType::ObjectState);
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
    for (Log::Logger *logger : m_loggers) {
        delete logger;
    }
}