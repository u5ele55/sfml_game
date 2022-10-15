
#include "lose_event.hpp"
#include "state_event.hpp"

namespace Map::Events
{
    LoseStateEvent::LoseStateEvent(GameState &state) : StateEvent(state) {}
    void LoseStateEvent::trigger() {
        m_state = GameState::LOSS;
        notify(Log::Message(Log::LogType::ObjectState, "LoseStateEvent triggered"));
    }
    LoseStateEvent::~LoseStateEvent() {}
} // namespace Map::Events
