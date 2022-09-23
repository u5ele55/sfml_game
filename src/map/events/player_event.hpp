#ifndef PLAYER_EVENT_HPP
#define PLAYER_EVENT_HPP

#include "event.hpp"
#include "../../objects/player.hpp"

namespace Map::Events
{
    class PlayerEvent : public Event {
    public:
        PlayerEvent(Objects::Player &);
    protected:
        Objects::Player &m_player;
    };
} // namespace Map

#endif