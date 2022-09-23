#ifndef DAMAGE_PLAYER_EVENT_HPP
#define DAMAGE_PLAYER_EVENT_HPP

#include "player_event.hpp"

namespace Map::Events
{
    class DamagePlayerEvent : public PlayerEvent {
    public:
        DamagePlayerEvent(const DamagePlayerEvent &) = delete;
        DamagePlayerEvent(DamagePlayerEvent&&) = delete;
        DamagePlayerEvent(Objects::Player &, int);
        void trigger() final;
    private:
        int m_damage;
    };
} // namespace Map::Events



#endif