#include "damage_player_event.hpp"

namespace Map::Events
{
    DamagePlayerEvent::DamagePlayerEvent(Objects::Player &player, int damage) 
      : PlayerEvent(player), m_damage(damage) {}

    void DamagePlayerEvent::trigger() {
        m_player.setHp(m_player.getHp() - m_damage);
    }
} // namespace Map::Events
