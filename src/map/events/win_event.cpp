
#include "win_event.hpp"
#include "state_event.hpp"
#include "../../log/messages/event_messages.hpp"

namespace Map::Events
{
    WinStateEvent::WinStateEvent(GameState &state) : StateEvent(state) {}
    void WinStateEvent::trigger() {
        m_state = GameState::WIN;
        notify(Log::EventMessages::win());
    }
    std::string WinStateEvent::toSlon() const {
        return "<Event name={Win}>";
    }
    WinStateEvent::~WinStateEvent() {}
} // namespace Map::Events
