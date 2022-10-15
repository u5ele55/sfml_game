#include "player_heal_event.hpp"

namespace Map::Events
{
    PlayerHealEvent::PlayerHealEvent(Common::CreatureWrapper &player) : PlayerEvent(player) {}
    void PlayerHealEvent::trigger() {
        int maxHp = m_player.creature.getMaxHp();
        if (m_player.creature.getHp() != maxHp)
            m_player.creature.setHp(maxHp);
        notify(Log::Message(Log::LogType::ObjectState, "PlayerHealEvent triggered"));
    }
    PlayerHealEvent::~PlayerHealEvent() {}
} // namespace Map::Events
