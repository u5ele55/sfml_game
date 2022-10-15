
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "observer.hpp"
#include <map>

namespace Log
{

    extern const std::map<LogType, std::string> prefix;

    class Logger : public Observer {
    public:
        virtual ~Logger() = default;
    protected:
        std::string formMessage(const Message &message) const;
    };
} // namespace Log


#endif