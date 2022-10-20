#include "logger_pool.hpp"

namespace Log
{

LoggerPool& LoggerPool::getInstance() {
    static LoggerPool pool;
    return pool;
}

void LoggerPool::addLogger( Logger *logger ) {
    m_loggers.push_back(logger);
}

LoggerPool::~LoggerPool() {
    for (Logger *l : m_loggers)
        delete l;
}
} // namespace Log
