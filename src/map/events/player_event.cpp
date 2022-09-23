#include "player_event.hpp"
#include "../../objects/player.hpp"

Map::Events::PlayerEvent::PlayerEvent(Objects::Player &player) : m_player(player) {}
