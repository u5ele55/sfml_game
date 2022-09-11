#include "object.hpp"
#include "../graphics/sprite_manager.hpp"

#include <iostream>

namespace Objects{
    Object::Object() : Object("", {0,0}) {}
    Object::Object(const std::string &spriteName) 
        : Object(spriteName, {0,0}) {}

    Object::Object(
        const std::string &spriteName, 
        Common::Vector2D<double> position, 
        bool isSolid
        ) : m_position(position), m_velocity(0,0), m_isSolid(isSolid), m_spriteName(spriteName)
    {
        Graphics::SpriteManager& spriteManager = Graphics::SpriteManager::getInstance();

        try {
            std::cout << "trying to get: " << spriteName << "..\n"; 
            sf::Sprite sprite = spriteManager.getSprite(spriteName);
            std::cout << "got it!\n";
            m_sprite = sprite;
        } catch (const std::invalid_argument e) {
            // what should i do?
            std::cout << "ABOBA!!!!";
        }
    }

    void Object::onUpdate(const sf::Time &elapsedTime) {
        double velocityModifier = 1;
        if (m_velocity.x != 0 && m_velocity.y != 0) {
            velocityModifier = 1 / 1.41;
        }
        m_position += m_velocity*elapsedTime.asSeconds() * velocityModifier;
        m_sprite.setPosition(m_position.x, m_position.y);
    }

    void Object::onInteraction(const Object&) {}
    void Object::onEvent(const sf::Event&) {}

    void Object::setSolidity(bool isSolid) {
        m_isSolid = isSolid;
    }
    bool Object::getSolidity() {
        return m_isSolid;
    }


    Common::Vector2D<double>& Object::position() {
        return m_position;
    }

    Common::Vector2D<double>& Object::velocity() {
        return m_velocity;
    }

    sf::Sprite& Object::sprite() {
        return m_sprite;
    }
}