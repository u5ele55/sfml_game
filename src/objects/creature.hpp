#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "object.hpp"

namespace Objects {
    enum Direction {
        LEFT, RIGHT, UP, DOWN
    };
    static const std::map<Direction, std::string> directionSuffix = {
        {DOWN, "_front"},
        {UP, "_back"},
        {LEFT, "_left"},
        {RIGHT, "_right"}
    };
    static const Direction directions[] = {LEFT, RIGHT, UP, DOWN};

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
        bool isAlive();
        void setMaxMana(int mana);
        int getMana();
        void setMeleeAttack(int meleeAttack);
        int getMeleeAttack();

        void setHp(int hp);
        void setMana(int mana);
        void setMageAttack(int attack);
        int getMageAttack();

        void setSpeed(double speed);
        void setFacing(const Direction& );
        Direction getFacing();
        CreatureType getCreatureType();
        /// @brief 
        /// Returns true if creature can go 
        /// @return 
        bool increaseStepPhase(double phase);
        
        bool canGo();

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