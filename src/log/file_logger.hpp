#ifndef FILE_LOGGER_HPP
#define FILE_LOGGER_HPP

#include "logger.hpp"
#include <fstream>


namespace Log
{
    class FileLogger : public Logger {
    public:
        FileLogger(const std::string &filename);
        void update(const Message &message);
        ~FileLogger();
    private:
        std::ofstream file;
    };
} // namespace Log


#endif