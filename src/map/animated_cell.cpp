#include "animated_cell.hpp"

namespace Objects {
    namespace Map
    {
        void AnimatedCell::onUpdate(const sf::Time &elapsedTime) {
            Graphics::SpriteManager &spriteManager = Graphics::SpriteManager::getInstance();
            auto sprites = spriteManager.getSprites(m_spriteName);
            m_frameCounter += elapsedTime.asSeconds();
            if (m_frameCounter >= sprites.size())
                m_frameCounter = 0;
            m_sprite = sprites[(int)m_frameCounter]; 
            Object::onUpdate(elapsedTime);
        }
    } // namespace Map
    
} // namespace Objects
