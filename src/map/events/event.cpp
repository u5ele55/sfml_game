#include "event.hpp"
#include <iostream>

namespace Map::Events
{
    Event::~Event() {
        std::cout << "~Event\n";
    }
} // namespace Map::Events
