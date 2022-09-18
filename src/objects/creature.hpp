#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "object.hpp"

namespace Objects {
    enum Direction {
        LEFT, RIGHT, UP, DOWN
    };

    enum CreatureType {
        PLAYER, DOG
    };
    
    class Creature : public Object {
    public:
        Creature() = delete;
        Creature( CreatureType type,
            int maxHp, int maxMana, int meleeAttack, int mageAttack,
            double speed, Direction facing = DOWN, double stepPhase = 0);

        void setMaxHp(int hp);
        bool isAlive() const;
        void setMaxMana(int mana);
        int getMana() const;
        void setMeleeAttack(int meleeAttack);
        int getMeleeAttack() const;

        void setHp(int hp);
        void setMana(int mana);
        void setMageAttack(int attack);
        int getMageAttack() const;

        void setSpeed(double speed);
        void setFacing(const Direction& );
        Direction getFacing() const;
        CreatureType getCreatureType() const;
        /// @brief 
        /// Returns true if creature can go 
        /// @return 
        bool increaseStepPhase(double phase);
        
        bool canGo() const;

        void makeStep();
    
    protected:
        int m_currentHp;
        int m_maxHp;
        int m_meleeAttack;
        int m_currentMana;
        int m_maxMana;
        int m_mageAttack;
        double m_speed;
        double m_stepPhase;
        bool m_canGo;

        CreatureType m_type;
        Direction m_facing;
    };
}
#endif