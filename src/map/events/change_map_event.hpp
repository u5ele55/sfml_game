#ifndef CHANGE_MAP_EVENT
#define CHANGE_MAP_EVENT

#include "map_event.hpp"
#include "../../common/creature_wrapper.hpp"
#include "../../common/vector2d.hpp"

namespace Map::Events
{
    class ChangeMapEvent : public MapEvent {
    public:
        ChangeMapEvent(
            Common::CreatureWrapper &player, const Common::Vector2D<int> &playerPosition,
            Map::FieldMap &map, const Map::FieldMap &newMap);
        void trigger() final;
    private:
        Common::CreatureWrapper &m_player;
        Common::Vector2D<int> m_playerPosition;
        Map::FieldMap m_newMap;
    };
} // namespace Map::Events


#endif