#include "player_event.hpp"
#include "../../objects/player.hpp"

Map::Events::PlayerEvent::PlayerEvent(Common::CreatureWrapper &player) : m_player(player) {}
