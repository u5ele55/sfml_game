#include "player_speed_multiplier_event.hpp"
#include "../../log/messages/event_messages.hpp"

namespace Map::Events
{
    PlayerSpeedMultiplierEvent::PlayerSpeedMultiplierEvent(Common::CreatureWrapper &player, double multiplier)
        : PlayerEvent(player), m_mlt(multiplier) {}
        
    void PlayerSpeedMultiplierEvent::trigger() {
        double newSpeed = m_player.creature.getSpeed() * m_mlt;

        if (newSpeed < 25) newSpeed = 25;
        if (newSpeed > 1000) newSpeed = 1000;
        
        m_player.creature.setSpeed(newSpeed);
        notify(Log::EventMessages::playerSpeed(newSpeed));
    }
    std::string PlayerSpeedMultiplierEvent::toSlon() const {
        std::stringstream stream;
        stream << "<Event name={PlayerSpeedMultiplier} multiplier={" << m_mlt << "}>";
        return stream.str();
    }
    PlayerSpeedMultiplierEvent::~PlayerSpeedMultiplierEvent() {}
} // namespace Map::Events
