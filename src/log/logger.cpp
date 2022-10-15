#include "logger.hpp"

namespace Log
{

const std::map<LogType, std::string> prefix = {
    {LogType::ObjectState, "[INFO]"},
    {LogType::GameState, "[GAME]"},
    {LogType::CriticalState, "[CRITICAL]"},
};

std::string Logger::formMessage(const Message &message) const {
    return (prefix.at(message.type()) + " " + message.message());
}

} // namespace Log
