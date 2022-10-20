#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include "log_types.hpp"
#include <string>

namespace Log
{
    class Message {
    public:
        Message(LogType type, std::string message);

        LogType type() const;
        std::string content() const;

        friend std::ostream& operator<<(std::ostream& stream, const Message &msg);

    private:
        LogType m_type;
        std::string m_msg;
    };
} // namespace Log


#endif