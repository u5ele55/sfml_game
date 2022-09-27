
#include "lose_event.hpp"
#include "state_event.hpp"

namespace Map::Events
{
    LoseStateEvent::LoseStateEvent(GameState &state) : StateEvent(state) {}
    void LoseStateEvent::trigger() {
        m_state = GameState::LOSS;
    }
} // namespace Map::Events
