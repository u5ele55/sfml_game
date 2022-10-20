
#include "lose_event.hpp"
#include "state_event.hpp"
#include "../../log/messages/event_messages.hpp"

namespace Map::Events
{
    LoseStateEvent::LoseStateEvent(GameState &state) : StateEvent(state) {}
    void LoseStateEvent::trigger() {
        m_state = GameState::LOSS;
        notify(Log::EventMessages::lose());
    }
    LoseStateEvent::~LoseStateEvent() {}
} // namespace Map::Events
