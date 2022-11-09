#ifndef PLAYER_POSITION_RULE
#define PLAYER_POSITION_RULE

#include "../../map.hpp"

namespace Map
{
    template <int x, int y>
    class PlayerPositionRule {
    public:
        static void changeMap(FieldMap &field) {
            field.player->position = {x,y};
        }
    };
} // namespace Map


#endif 