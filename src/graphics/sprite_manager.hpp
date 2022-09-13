#ifndef SPRITE_MANAGER_HPP
#define SPRITE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include "../objects/creature.hpp"

namespace Graphics {
    class SpriteManager {
    public:
        SpriteManager(const SpriteManager&) = delete;
        SpriteManager(SpriteManager&&) = delete;
        SpriteManager& operator=(const SpriteManager&) = delete;
        SpriteManager& operator=(SpriteManager&&) = delete;

        static SpriteManager& getInstance();

        std::map<Objects::Direction, sf::Sprite> getCreatureSprites(
            const Objects::CreatureType&);
        /// @brief 
        /// Returns single sprite with given name.
        /// @return 
        sf::Sprite getSprite(const std::string& name);
    private:
        SpriteManager();

        std::map<std::string, std::vector<sf::Sprite>> m_sprites;
    };
}

#endif