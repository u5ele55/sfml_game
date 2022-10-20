#ifndef EVENT_MESSAGES_HPP
#define EVENT_MESSAGES_HPP

#include "message_storage.hpp"
#include "../../common/vector2d.hpp"

namespace Log
{
    class EventMessages : public MessageStorage {
    public:
        static Message healPlayer();
        static Message damagePlayer(int newHP);
        static Message changeCells();
        static Message changeMap();
        static Message lose();
        static Message win();
        static Message playerSpeed(double newSpeed);
    };
} // namespace Log


#endif