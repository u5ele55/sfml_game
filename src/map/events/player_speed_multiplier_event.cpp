#include "player_speed_multiplier_event.hpp"
#include <iostream>

namespace Map::Events
{
    PlayerSpeedMultiplierEvent::PlayerSpeedMultiplierEvent(Common::CreatureWrapper &player, double multiplier)
        : PlayerEvent(player), m_mlt(multiplier) {}
    void PlayerSpeedMultiplierEvent::trigger() {
        double newSpeed = m_player.creature.getSpeed() * m_mlt;

        if (newSpeed < 25) newSpeed = 25;
        if (newSpeed > 1000) newSpeed = 1000;
        
        m_player.creature.setSpeed(newSpeed);
        notify(Log::Message(
            Log::LogType::ObjectState, 
            "PlayerSpeedMultiplierEvent triggered, newSpeed="+std::to_string(newSpeed))
            );
    }
    PlayerSpeedMultiplierEvent::~PlayerSpeedMultiplierEvent() {}
} // namespace Map::Events
