#ifndef PLAYER_HEAL_EVENT
#define PLAYER_HEAL_EVENT

#include "player_event.hpp"

namespace Map::Events
{
    class PlayerHealEvent : public PlayerEvent {
    public:
        PlayerHealEvent(Common::CreatureWrapper &player);
        void trigger() final;
    };
} // namespace Map::Events


#endif