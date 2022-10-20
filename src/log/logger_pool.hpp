#ifndef LOGGER_POOL
#define LOGGER_POOL

#include "logger.hpp"
#include <vector>

namespace Log
{
    class LoggerPool {
    public:
        LoggerPool(const LoggerPool&) = delete;
        LoggerPool(LoggerPool&&) = delete;
        LoggerPool& operator=(LoggerPool&&) = delete;
        LoggerPool& operator=(const LoggerPool&) = delete;
        ~LoggerPool();

        static LoggerPool& getInstance();
        
        void addLogger( Logger *logger );

    private:
        LoggerPool() = default;
        std::vector<Logger*> m_loggers;
    };
} // namespace Log


#endif