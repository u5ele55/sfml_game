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

void Logger::addLogType(const LogType &type) {
    if (!logTypeAvailable(type))
        m_types.push_back(type);
}

void Logger::deleteLogType(const LogType &type) {
    for (int i = 0; i < m_types.size(); i ++)
        if (m_types[i] == type) {
            m_types.erase(m_types.begin()+i);
            return;
        }
}

bool Logger::logTypeAvailable(const LogType &type) const {
    for (const auto &t : m_types) 
        if (type == t) return true;
    return false;
}

} // namespace Log
