#ifndef EVENT_HPP
#define EVENT_HPP

namespace Map
{
    namespace Events
    {
        class Event {
        public:
            virtual void trigger() = 0;
            virtual ~Event() = 0;
        };  
    } // namespace Events
    
} // namespace Map

#endif