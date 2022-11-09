#ifndef LOSE_POSITION_RULE
#define LOSE_POSITION_RULE

#include "../../map.hpp"
#include "../../events/lose_event.hpp"

namespace Map
{
    template <int x, int y>
    class LoseEventPositionRule {
    public:
        static void changeMap(FieldMap &field) {
            field.setCellEvent({x,y}, new Events::LoseStateEvent(*field.state));
        }
    };
} // namespace Map


#endif