#include "file_logger.hpp"

#include <iostream>

namespace Log
{
    FileLogger::FileLogger(const std::string &filename) {
        file.open(filename);
    }

    void FileLogger::update(const Message &message) {
        if (logTypeAvailable(message.type()))
            file << formMessage(message) << '\n';
    }

    FileLogger::~FileLogger() {
        file.close();
    }
} // namespace Log
