#include "creature.hpp"

namespace Objects {
    std::map<Direction, std::string> dirStr = {
            {DOWN, "_front"},
            {UP, "_back"},
            {LEFT, "_left"},
            {RIGHT, "_right"}
        };
    Creature::Creature(
        const std::string& spriteName, 
        int maxHp, int maxMana, 
        int meleeAttack, int mageAttack,
        double speed, Direction facing)
      : Object(spriteName) 
    {
        m_currentHp = maxHp;
        m_maxHp = maxHp;
        m_meleeAttack = meleeAttack;
        m_maxMana = maxMana;
        m_currentMana = maxMana;
        m_mageAttack = mageAttack;
        m_speed = speed;
        m_facing = facing;
    }

    void Creature::onUpdate(const sf::Time &elapsedTime) {
        Graphics::SpriteManager &spriteManager = Graphics::SpriteManager::getInstance();

        auto sprites = spriteManager.getSprites(m_spriteName+dirStr[m_facing]);
        static double frameNumber = 0;
        if (m_velocity != Common::Vector2D<double>(0,0)) {
            frameNumber += elapsedTime.asSeconds() * m_speed*1.0 / 20
                        + (frameNumber == 0 ? 1 : 0);
            if (frameNumber >= sprites.size()) 
                frameNumber -= sprites.size();
        } else {
            frameNumber = 0;
        }
        m_sprite = sprites[(int)frameNumber]; 
        Object::onUpdate(elapsedTime);
    }

    void Creature::setHp(int hp) {
        m_currentHp = hp;
    }
    void Creature::setMaxHp(int hp) {
        m_maxHp = hp;
    }
    void Creature::setMana(int mana) {
        m_currentMana = mana;
    }
    void Creature::setMaxMana(int mana) {
        m_maxMana = mana;
    }
    void Creature::setMageAttack(int attack) {
        m_mageAttack = attack;
    }
    void Creature::setMeleeAttack(int attack) {
        m_meleeAttack = attack;
    }
    void Creature::setSpeed(double speed) {
        m_speed = speed;
    }
}