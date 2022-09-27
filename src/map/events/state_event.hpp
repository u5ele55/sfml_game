#ifndef STATE_EVENT_HPP
#define STATE_EVENT_HPP

#include "event.hpp"
#include "../../game/game_state.hpp"

namespace Map::Events
{
    class StateEvent : public Event {
    public:
        StateEvent( GameState &state );
    protected:
        GameState &m_state;
    };
} // namespace Map::Events

#endif