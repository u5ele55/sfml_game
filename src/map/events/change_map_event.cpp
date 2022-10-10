#include "change_map_event.hpp"
#include <iostream>

namespace Map::Events
{
    ChangeMapEvent::ChangeMapEvent(
        Common::CreatureWrapper &player, const Common::Vector2D<int> &playerPosition,
        Map::FieldMap &map, const Map::FieldMap &newMap)
        : MapEvent(map), m_player(player), m_newMap(newMap), m_playerPosition(playerPosition) {}

    void ChangeMapEvent::trigger() {
        std::cout << "trigger changemap\n";
        for (int i = 0; i < m_map.getSize().y; i ++) {
            for (int j = 0; j < m_map.getSize().x; j ++)
                std::cout << (int)m_map.getCellType(j, i) << " ";
            std::cout << '\n';
        }
        std::cout << "TO\n";
        m_map = m_newMap;
        std::cout << m_map.getSize().y << " " << m_map.getSize().x << '\n';
        for (int i = 0; i < m_map.getSize().y; i ++) {
            for (int j = 0; j < m_map.getSize().x; j ++)
                std::cout << (int)m_map.getCellType(j, i) << " ";
            std::cout << '\n';
        }
        std::cout << "map changed\n";
        m_player.position = m_playerPosition;
    }
    ChangeMapEvent::~ChangeMapEvent() {}
} // namespace Map::Events
