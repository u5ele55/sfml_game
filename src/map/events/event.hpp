#ifndef EVENT_HPP
#define EVENT_HPP

#include "../../log/observable.hpp"

namespace Map
{
    namespace Events
    {
        class Event : public Log::Observable {
        public:
            virtual void trigger() = 0;
            virtual ~Event() = 0;
        };  
    } // namespace Events
    
} // namespace Map

#endif