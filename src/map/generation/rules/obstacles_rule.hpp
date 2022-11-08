#ifndef OBSTACLES_RULE
#define OBSTACLES_RULE

#include "../../map.hpp"

namespace Map
{
    enum class ObstaclesVariant {
        SPIRAL, ROOMS
    };

    template <ObstaclesVariant variant>
    class ObstaclesRule {
    public:
        static void changeMap(FieldMap &field) {
            if (variant == ObstaclesVariant::ROOMS) {
                field.setCell({0,0}, Cell(TileType::STONE, true));
            } else {
                field.setCell({0,0}, Cell(TileType::STONE, true));
                field.setCell({0,2}, Cell(TileType::STONE, true));
                field.setCell({0,1}, Cell(TileType::STONE, true));
            }
        }
    };
} // namespace Map


#endif