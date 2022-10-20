#include "message.hpp"
#include "log_types.hpp"
#include "log_prefix.hpp"

namespace Log
{

    Message::Message(LogType type, std::string message) : m_type(type), m_msg(message) {}

    std::string Message::content() const {return m_msg;}
    Log::LogType Log::Message::type() const {return m_type;}

    std::ostream& operator<<(std::ostream& stream, const Message &msg) {
        stream << (prefix.at(msg.m_type) + " ") << msg.m_msg;
        return stream;
    }
    
} // namespace Log
