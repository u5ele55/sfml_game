#ifndef PLAYER_MESSAGES_HPP
#define PLAYER_MESSAGES_HPP

#include "message_storage.hpp"
#include "../../common/vector2d.hpp"

namespace Log
{
    class PlayerMessages : public MessageStorage {
    public:
        static Message changedPosition(const Common::Vector2D<int> &position);
        static Message triesToPassSolidCell(const Common::Vector2D<int> &position);
    };
} // namespace Log


#endif