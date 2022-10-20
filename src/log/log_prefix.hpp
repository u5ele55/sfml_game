#ifndef LOG_PREFIX_HPP
#define LOG_PREFIX_HPP

#include <map>
#include "log_types.hpp"

namespace Log
{
const std::map<LogType, std::string> prefix = {
    {LogType::ObjectState, "[INFO]"},
    {LogType::GameState, "[GAME]"},
    {LogType::CriticalState, "[CRITICAL]"},
};
} // namespace Log

#endif