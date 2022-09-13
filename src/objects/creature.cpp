#include "creature.hpp"

namespace Objects {

    const double stepPause = 1000;
    
    
    Creature::Creature(
        CreatureType type,
        int maxHp, int maxMana, 
        int meleeAttack, int mageAttack,
        double speed, Direction facing
        ) : m_type(type), 
            m_currentHp(maxHp), 
            m_maxHp(maxHp), 
            m_meleeAttack(meleeAttack),
            m_maxMana(maxMana),
            m_currentMana(maxMana),
            m_mageAttack(mageAttack),
            m_speed(speed),
            m_facing(facing), 
            Object() {}
    

    void Creature::setHp(int hp) {m_currentHp = hp;}
    void Creature::setMaxHp(int hp) {m_maxHp = hp;}
    void Creature::setMana(int mana) {m_currentMana = mana;}
    void Creature::setMaxMana(int mana) {m_maxMana = mana;}
    void Creature::setMageAttack(int attack) {m_mageAttack = attack;}
    void Creature::setMeleeAttack(int attack) {m_meleeAttack = attack;}
    void Creature::setSpeed(double speed) {m_speed = speed;}
    void Creature::setFacing(const Direction& direction) {m_facing = direction;}
    Direction Creature::getFacing() {return m_facing;}
    bool Creature::isAlive() {return m_currentHp > 0;}
    int Creature::getMeleeAttack() {return m_meleeAttack;}
    int Creature::getMageAttack() {return m_mageAttack;}
    int Creature::getMana() {return m_currentMana;}
    CreatureType Creature::getCreatureType() {return m_type;}

    bool Creature::canGo() {return m_canGo;}

    void Creature::makeStep() {
        m_canGo = false;
        m_stepPhase = 0;
    }

    bool Creature::increaseStepPhase(double phase) {
        m_stepPhase += m_speed * phase;
        if (m_stepPhase > Objects::stepPause) {
            m_canGo = true;
            return true;
        }
        return false;
    }
}