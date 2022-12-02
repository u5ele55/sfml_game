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
    std::string DamagePlayerEvent::toString() const {
        std::stringstream stream;
        stream << "damage " << m_damage;
        return stream.str();
    }
    DamagePlayerEvent::~DamagePlayerEvent() {}
} // namespace Map::Events
