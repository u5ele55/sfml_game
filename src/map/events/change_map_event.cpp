#include "change_map_event.hpp"
#include <iostream>

namespace Map::Events
{
    ChangeMapEvent::ChangeMapEvent(
        Common::CreatureWrapper &player, const Common::Vector2D<int> &playerPosition,
        Map::FieldMap &map, const Map::FieldMap &newMap)
        : MapEvent(map), m_player(player), m_newMap(newMap), m_playerPosition(playerPosition) {}

    void ChangeMapEvent::trigger() {
        m_map = m_newMap;
        m_player.position = m_playerPosition;
        
        notify(Log::Message(Log::LogType::ObjectState, "ChangeMapEvent triggered"));
    }
    
    ChangeMapEvent::~ChangeMapEvent() {}
} // namespace Map::Events
