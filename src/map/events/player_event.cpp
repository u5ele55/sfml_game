#include "player_event.hpp"
#include "../../objects/player.hpp"
#include <iostream>

namespace Map::Events
{
    PlayerEvent::PlayerEvent(Common::CreatureWrapper &player) : m_player(player) {}
    PlayerEvent::~PlayerEvent() {}
} // namespace Map::Events


