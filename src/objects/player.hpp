#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "creature.hpp"

namespace Objects {
    class Player : public Creature {
    public:
        Player();
        void onEvent(const sf::Event&) override;
    };
}
#endif