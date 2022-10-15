#include "message.hpp"
#include "log_types.hpp"

namespace Log
{

    Message::Message(LogType type, std::string message) : m_type(type), m_msg(message) {}

    std::string Message::message() const {return m_msg;}
    Log::LogType Log::Message::type() const {return m_type;}
    
} // namespace Log
