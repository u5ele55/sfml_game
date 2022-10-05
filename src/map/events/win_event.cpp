
#include "win_event.hpp"
#include "state_event.hpp"

namespace Map::Events
{
    WinStateEvent::WinStateEvent(GameState &state) : StateEvent(state) {}
    void WinStateEvent::trigger() {
        m_state = GameState::WIN;
    }
    WinStateEvent::~WinStateEvent() {}
} // namespace Map::Events
