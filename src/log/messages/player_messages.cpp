#include "player_messages.hpp"

namespace Log
{

Message PlayerMessages::changedPosition(const Common::Vector2D<int> &position) {
    std::string x = std::to_string(position.x),
				y = std::to_string(position.y);
	std::string pos = "["+x+", "+y+"]";
    return Message(LogType::ObjectState, "Player position : "+pos);
}
Message PlayerMessages::triesToPassSolidCell(const Common::Vector2D<int> &position) {
    std::string x = std::to_string(position.x),
				y = std::to_string(position.y);
	std::string pos = "["+x+", "+y+"]";
    return Message(LogType::CriticalState, "Player tries to pass through solid cell " + pos);
}   

} // namespace Log
