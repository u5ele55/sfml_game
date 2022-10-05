#ifndef LOSE_EVENT_HPP
#define LOSE_EVENT_HPP

#include "state_event.hpp"

namespace Map::Events
{
    class LoseStateEvent : public StateEvent {
    public:
        LoseStateEvent(GameState &state);
        void trigger() final;
        ~LoseStateEvent();
    };

} // namespace Map::Events


#endif