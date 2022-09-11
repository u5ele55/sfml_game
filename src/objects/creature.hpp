#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "object.hpp"

namespace Objects {
    enum Direction {
        LEFT, RIGHT, UP, DOWN
    };

    class Creature : public Object {
    public:
        Creature() = delete;
        Creature(
            const std::string& spriteName, 
            int maxHp, int maxMana, int meleeAttack, int mageAttack,
            double speed, Direction facing = DOWN);

        void onUpdate(const sf::Time&) override;

        void setMaxHp(int hp);
        void setMaxMana(int mana);
        void setMeleeAttack(int meleeAttack);

        void setHp(int hp);
        void setMana(int mana);
        void setMageAttack(int attack);

        void setSpeed(double speed);
    protected:
        int m_currentHp;
        int m_maxHp;
        int m_meleeAttack;
        int m_currentMana;
        int m_maxMana;
        int m_mageAttack;
        int m_speed;
        Direction m_facing;
    };
}
#endif