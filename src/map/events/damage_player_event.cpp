#include "damage_player_event.hpp"

namespace Map::Events
{
    DamagePlayerEvent::DamagePlayerEvent(Common::CreatureWrapper &player, int damage) 
      : PlayerEvent(player), m_damage(damage) {}

    void DamagePlayerEvent::trigger() {
      int newHp = m_player.creature.getHp() - m_damage;
      m_player.creature.setHp(newHp);
      notify(Log::Message(
        Log::LogType::ObjectState, 
        "DamagePlayerEvent triggered. New hp: " + std::to_string(newHp)));
    }
    DamagePlayerEvent::~DamagePlayerEvent() {}
} // namespace Map::Events
