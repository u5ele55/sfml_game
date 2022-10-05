#include "map_event.hpp"

namespace Map::Events
{
    MapEvent::MapEvent(FieldMap &map) : m_map(map) {}
    MapEvent::~MapEvent() {}
} // namespace Map::Events

