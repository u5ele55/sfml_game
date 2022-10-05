#include "state_event.hpp"

namespace Map::Events
{
    StateEvent::StateEvent(GameState &state) : m_state(state) {}
    StateEvent::~StateEvent() {}
} // namespace Map::Events
