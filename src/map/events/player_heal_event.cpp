#include "player_heal_event.hpp"
#include "../../log/messages/event_messages.hpp"

namespace Map::Events
{
    PlayerHealEvent::PlayerHealEvent(Common::CreatureWrapper &player) : PlayerEvent(player) {}
    void PlayerHealEvent::trigger() {
        int maxHp = m_player.creature.getMaxHp();
        if (m_player.creature.getHp() != maxHp)
            m_player.creature.setHp(maxHp);
        notify(Log::EventMessages::healPlayer());
    }
    std::string PlayerHealEvent::toString() const {
        return "heal";
    }
    PlayerHealEvent::~PlayerHealEvent() {}
} // namespace Map::Events
