#include "damage_player_event.hpp"
#include "../../log/messages/event_messages.hpp"

namespace Map::Events
{
    DamagePlayerEvent::DamagePlayerEvent(Common::CreatureWrapper &player, int damage) 
      : PlayerEvent(player), m_damage(damage) {}

    void DamagePlayerEvent::trigger() {
      int newHp = m_player.creature.getHp() - m_damage;
      m_player.creature.setHp(newHp);
      notify(Log::EventMessages::damagePlayer(newHp));
    }
    DamagePlayerEvent::~DamagePlayerEvent() {}
} // namespace Map::Events
