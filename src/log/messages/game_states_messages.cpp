#include "game_states_messages.hpp"

namespace Log
{
Message GameStateMessages::win() {
    return Message(LogType::GameState, "Win!");
}
Message GameStateMessages::lose() {
    return Message(LogType::GameState, "Loss!");
}
Message GameStateMessages::gameStarted() {
    return Message(LogType::GameState, "Game started");
}
Message GameStateMessages::mapChoosen() {
    return Message(LogType::GameState, "Map choosen");
}
Message GameStateMessages::errorOnMapChoice(const std::string &e) {
    return Message(LogType::CriticalState, e);
}
Message GameStateMessages::wrongMapChoice() {
    return Message(LogType::CriticalState, "Wrong map choice");
}
Message GameStateMessages::windowClosed() {
    return Message(LogType::GameState, "Window closed");
}
} // namespace Log

