#ifndef WIN_POSITION_RULE
#define WIN_POSITION_RULE

#include "../../map.hpp"
#include "../../events/win_event.hpp"

namespace Map
{
    template <int x, int y>
    class WinEventPositionRule {
    public:
        static void changeMap(FieldMap &field) {
            field.setCellEvent({x,y}, new Events::WinStateEvent(*field.state));
        }
    };
} // namespace Map


#endif