#ifndef EVENT_CREATOR
#define EVENT_CREATOR

#include "event.hpp"

namespace Map
{
    class EventCreator {
    public:
        virtual Events::Event* fromSlon(std::string slon) = 0;
    };
} // namespace Map


#endif