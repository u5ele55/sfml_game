#include "player.hpp"
#include <iostream>

namespace Objects {
    Player::Player() : Creature(CreatureType::PLAYER, 100,100,10,25, 200) {}
}