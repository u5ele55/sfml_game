#ifndef WIN_EVENT_HPP
#define WIN_EVENT_HPP

#include "state_event.hpp"
#include "../../game/game_state.hpp"

namespace Map::Events
{
    class WinStateEvent : public StateEvent {
    public:
        WinStateEvent(GameState &state);
        ~WinStateEvent();
        void trigger() final;
        std::string toSlon() const;
    };
} // namespace Map::Events

#endif