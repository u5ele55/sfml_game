#include "console_logger.hpp"
#include "logger.hpp"
#include <iostream>

namespace Log
{

void ConsoleLogger::update(const Message &message) {
    std::cout << formMessage(message) << '\n';
}

} // namespace Log
