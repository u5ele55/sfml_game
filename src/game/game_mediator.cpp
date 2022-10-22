#include "game_mediator.hpp"
#include "../log/console_logger.hpp"
#include "../log/file_logger.hpp"
#include "../log/logger_pool.hpp"

#include <iostream>

GameMediator::GameMediator() {
    m_eventReader = new SfmlEventReader(this);
    m_game = new GameCore(this);

    Log::Logger *logger = new Log::FileLogger("log.txt");
    m_game->subscribe(logger);
    logger->addLogType(Log::LogType::CriticalState);
    
    Log::Logger *loggerC = new Log::ConsoleLogger;
    m_game->subscribe(loggerC);
    loggerC->addLogType(Log::LogType::GameState);
    loggerC->addLogType(Log::LogType::ObjectState);

    auto &loggerPool = Log::LoggerPool::getInstance();
    loggerPool.addLogger(logger);
    loggerPool.addLogger(loggerC);
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