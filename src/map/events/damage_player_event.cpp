#include "damage_player_event.hpp"

namespace Map::Events
{
    DamagePlayerEvent::DamagePlayerEvent(Common::CreatureWrapper &player, int damage) 
      : PlayerEvent(player), m_damage(damage) {}

    void DamagePlayerEvent::trigger() {
        m_player.creature.setHp(m_player.creature.getHp() - m_damage);
    }
} // namespace Map::Events
