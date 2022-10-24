#include "game_mediator.hpp"
#include "../log/console_logger.hpp"
#include "../log/file_logger.hpp"
#include "../log/logger_pool.hpp"

#include <iostream>

GameMediator::GameMediator() {
    m_eventReader = new SfmlEventReader(this, Controls::ControlsStorage("controls.txt"));
    m_game = new GameCore(this);
    configureLogging();
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

void GameMediator::configureLogging() {
    auto &loggerPool = Log::LoggerPool::getInstance();
    std::cout << "Logging configuration.\n";
    std::cout << "Enter 0 to skip, 1 to add ConsoleLogger, 2 to add FileLogger\n";
    int choice;
    std::cin >> choice;

    while (choice) {
        
        std::string filename;
        Log::Logger *logger;
        bool err = false;
        switch (choice)
        {
        case 1:
            logger = new Log::ConsoleLogger;
            break;
        case 2:
            std::cout << "Enter file name to log into: ";
            std::cin >> filename;
            logger = new Log::FileLogger(filename);
            break;
        default:
            err = true;
            std::cout << "Invalid choice\n";
            break;
        }
        if (!err) {
            std::cout << "To make logger log levels, input sum of numbers next to log level that"
                  << " should be logged : GameState - 1; ObjectState - 2; CriticalState - 4: ";
            int sum;
            std::cin >> sum;
            if (sum & 1)
                logger->addLogType(Log::LogType::GameState);
            if (sum/2 & 1)
                logger->addLogType(Log::LogType::ObjectState);
            if (sum/4 & 1)
                logger->addLogType(Log::LogType::CriticalState);
            m_game->subscribe(logger);
            
            loggerPool.addLogger(logger);
        }

        std::cout << "Enter 0 to skip, 1 to add ConsoleLogger, 2 to add FileLogger\n";
        std::cin >> choice;
    }
}