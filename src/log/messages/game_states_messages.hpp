#ifndef GAME_STATE_MESSAGES_HPP
#define GAME_STATE_MESSAGES_HPP

#include "message_storage.hpp"
#include "../../common/vector2d.hpp"

namespace Log
{
    class GameStateMessages : public MessageStorage {
    public:
        static Message win();
        static Message lose();
        static Message gameStarted();
        static Message mapChoosen();
        static Message errorOnMapChoice(const std::string &e);
        static Message wrongMapChoice();
        static Message windowClosed();
    };
} // namespace Log


#endif