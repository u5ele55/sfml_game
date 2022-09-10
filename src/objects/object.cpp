#include "object.hpp"
#include "../graphics/texture_manager.hpp"

#include <iostream>

Object::Object() : Object(Graphics::Tile, {0,0}) {}
Object::Object(const Graphics::TextureType &textureType) 
    : Object(textureType, {0,0}) {}

Object::Object(
    const Graphics::TextureType &textureType, 
    Common::Vector2D<double> position, 
    bool isSolid
    ) : m_position(position), m_velocity(0,0), m_isSolid(isSolid) 
{
    Graphics::TextureManager& textureManager = Graphics::TextureManager::getInstance();

    try {
        sf::Texture* texture = textureManager.getTexture(textureType);
        m_sprite.setTexture(*texture);
    } catch (const std::invalid_argument e) {
        // what should i do?
        std::cout << "ABOBA!!!!";
    }
}

void Object::onUpdate(const sf::Time &elapsedTime) {
    m_position += m_velocity*elapsedTime.asSeconds();
}

void Object::onInteraction(const Object&) {
    // nothing here...
}

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