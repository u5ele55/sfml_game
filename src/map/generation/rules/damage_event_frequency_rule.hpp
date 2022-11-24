#ifndef DAMAGE_EVENT_FREQUENCY_RULE
#define DAMAGE_EVENT_FREQUENCY_RULE

#include "../../map.hpp"
#include "../../events/damage_player_event.hpp"

#include <cstdlib>
#include <iostream>

namespace Map
{
    template <int probability, int damage = 20>
    class DamageEventFrequencyRule {
    public:
        static void changeMap(FieldMap &field) {
            const auto &size = field.getSize();
            for(int i = 0; i < size.y; i ++) 
                for (int j = 0; j < size.x; j ++) 
                    if (rand() % 100 < probability) {
                        if (!field.cellHasEvent(j, i))
                            field.setCellEvent({j,i}, new Events::DamagePlayerEvent(*field.player, damage));
                    }
            
        }
    };
} // namespace Map


#endif 