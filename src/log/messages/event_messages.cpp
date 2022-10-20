#include "event_messages.hpp"

namespace Log
{

Message EventMessages::healPlayer() {
    return Message(LogType::ObjectState, "PlayerHealEvent triggered");
}
Message EventMessages::damagePlayer(int newHP) {
    return Message(
        LogType::ObjectState, 
        "DamagePlayerEvent triggered. New hp: " + std::to_string(newHP));
}

Message EventMessages::changeCells() {
    return Message(LogType::ObjectState, "ChangeCellsEvent triggered");
}
Message EventMessages::changeMap() {
    return Message(LogType::ObjectState, "ChangeMapEvent triggered");
}

Message EventMessages::lose() {
    return Message(LogType::ObjectState, "LoseStateEvent triggered");
}
Message EventMessages::win() {
    return Message(LogType::ObjectState, "WinStateEvent triggered");
}

Message EventMessages::playerSpeed(double newSpeed) {
    return Message(
        Log::LogType::ObjectState, 
        "PlayerSpeedMultiplierEvent triggered, newSpeed=" + std::to_string(newSpeed));
}


} // namespace Log
