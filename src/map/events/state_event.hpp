#ifndef STATE_EVENT_HPP
#define STATE_EVENT_HPP

#include "event.hpp"

namespace Map::Events
{
    class StateEvent : public Event {
    public:
        StateEvent( int &state );
    private:
        int &m_state;
    };
} // namespace Map::Events


#endif