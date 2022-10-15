#include "creature.hpp"
#include <iostream>

namespace Objects {

    const double stepPause = 100;
    
    
    Creature::Creature(
        CreatureType type,
        int maxHp, int maxMana, 
        int meleeAttack, int mageAttack,
        double speed, Direction facing,
        double stepPhase
        ) : m_type(type), 
            m_currentHp(maxHp), 
            m_maxHp(maxHp), 
            m_meleeAttack(meleeAttack),
            m_maxMana(maxMana),
            m_currentMana(maxMana),
            m_mageAttack(mageAttack),
            m_speed(speed),
            m_facing(facing), 
            m_stepPhase(stepPhase),
            m_canGo(stepPhase > stepPause) {}
    

    void Creature::setHp(int hp) {m_currentHp = hp;}
    void Creature::setMaxHp(int hp) {m_maxHp = hp;}
    void Creature::setMana(int mana) {m_currentMana = mana;}
    void Creature::setMaxMana(int mana) {m_maxMana = mana;}
    void Creature::setMageAttack(int attack) {m_mageAttack = attack;}
    void Creature::setMeleeAttack(int attack) {m_meleeAttack = attack;}
    void Creature::setSpeed(double speed) {m_speed = speed;}
    void Creature::setFacing(const Direction& direction) {m_facing = direction;}
    Direction Creature::getFacing() const {return m_facing;}
    double Creature::getSpeed() const {return m_speed;}
    bool Creature::isAlive() const {return m_currentHp > 0;}
    int Creature::getMeleeAttack() const {return m_meleeAttack;}
    int Creature::getMageAttack() const {return m_mageAttack;}
    int Creature::getMana() const {return m_currentMana;}
    int Creature::getMaxMana() const {return m_maxMana;}
    int Creature::getMaxHp() const {return m_maxHp;}
    int Creature::getHp() const {return m_currentHp;}

    CreatureType Creature::getCreatureType() const {return m_type;}

    bool Creature::canGo() const {return m_canGo;}

    void Creature::makeStep() {
        m_canGo = false;
        m_stepPhase = 0;
    }

    bool Creature::increaseStepPhase(const double& phase) {
        m_stepPhase += m_speed * phase;
        
        if (m_stepPhase > Objects::stepPause)
            m_canGo = true;
 
        return m_canGo;
    }

    std::ostream &operator<<(std::ostream &stream, const Creature& creature) {
        stream << "<Creature type=" << (int)creature.m_type 
            << " hp: " << creature.m_currentHp << "/" << creature.m_maxHp 
            << " mana: " << creature.m_currentMana << "/" << creature.m_maxMana
            << " facing=" << (int)creature.m_facing
            << " speed=" << creature.m_speed
               << ">"; 
        return stream;
    }
}