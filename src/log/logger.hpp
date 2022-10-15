
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "observer.hpp"
#include <map>
#include <vector>

namespace Log
{

    extern const std::map<LogType, std::string> prefix;

    class Logger : public Observer {
    public:
        void addLogType(const LogType &type);
        void deleteLogType(const LogType &type);
    protected:
        std::string formMessage(const Message &message) const;
        bool logTypeAvailable(const LogType &type) const;
    private:
        std::vector<LogType> m_types;
    };
} // namespace Log


#endif