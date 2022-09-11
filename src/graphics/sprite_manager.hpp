#ifndef SPRITE_MANAGER_HPP
#define SPRITE_MANAGER_HPP

#include <SFML/Graphics.hpp>

namespace Graphics {
    class SpriteManager {
    public:
        SpriteManager(const SpriteManager&) = delete;
        SpriteManager(SpriteManager&&) = delete;
        SpriteManager& operator=(const SpriteManager&) = delete;
        SpriteManager& operator=(SpriteManager&&) = delete;

        static SpriteManager& getInstance();
        /// @brief 
        /// Returns vector of sprites.
        /// Use getSprite if object don't have any animation.
        /// @return 
        std::vector<sf::Sprite> getSprites(const std::string& name);
        /// @brief 
        /// Returns single sprite.
        /// Use getSprites if object have animation.
        /// @return 
        sf::Sprite getSprite(const std::string& name);
    private:
        SpriteManager();

        std::map<std::string, std::vector<sf::Sprite>> m_sprites;
    };
}

#endif