#ifndef PLAYER_SPEED_MLT_HPP
#define PLAYER_SPEED_MLT_HPP

#include "player_event.hpp"

namespace Map::Events
{
    class PlayerSpeedMultiplierEvent : public PlayerEvent {
    public:
        PlayerSpeedMultiplierEvent(Common::CreatureWrapper &player, double multiplier);
        ~PlayerSpeedMultiplierEvent();
        void trigger() final;
    private:
        double m_mlt;
    };
} // namespace Map::Events


#endif