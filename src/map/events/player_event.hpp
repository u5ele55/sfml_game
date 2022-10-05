#ifndef PLAYER_EVENT_HPP
#define PLAYER_EVENT_HPP

#include "event.hpp"
#include "../../common/creature_wrapper.hpp"

namespace Map::Events
{
    class PlayerEvent : public Event {
    public:
        PlayerEvent(Common::CreatureWrapper &);
        ~PlayerEvent();
    protected:
        Common::CreatureWrapper &m_player;
    };
} // namespace Map

#endif