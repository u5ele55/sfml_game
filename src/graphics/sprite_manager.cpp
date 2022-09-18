#include "sprite_manager.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include "texture_manager.hpp"


namespace Graphics {
    SpriteManager::SpriteManager() {
        TextureManager& textureManager = TextureManager::getInstance();
        std::string path = "assets/textures/";
        std::map<TextureType, std::string> typeFilenames = {
            {Player, "player_sprites"},
            {Tile, "tiles"}
        };
        for (TextureType type : existingTypes) {
            std::string spriteFile = path+typeFilenames[type];
            std::ifstream in(spriteFile);
            int spriteGroups;
            in >> spriteGroups;
            for (int _q = 0; _q < spriteGroups; _q ++) {
                std::string spriteName;
                int spriteCnt;
                in >> spriteName >> spriteCnt;
                std::cout << spriteName << " " << spriteCnt << '\n'; 
                m_sprites[spriteName] = std::vector<sf::Sprite>(spriteCnt, sf::Sprite());
                sf::Texture *texture = textureManager.getTexture(type);

                for (int i = 0; i < spriteCnt; i ++) {
                    int l, t, w, h; in >> l >> t >> w >> h;
                    m_sprites[spriteName][i].setTexture(*texture);
                    m_sprites[spriteName][i].setTextureRect(sf::IntRect(l, t, w, h));
                }
            }

            in.close();
        }
    }

    SpriteManager& SpriteManager::getInstance() {
        static SpriteManager textureManager;
        return textureManager;
    }

    sf::Sprite SpriteManager::getSprite(const std::string &name) {
        if (m_sprites.count(name) == 0 || m_sprites[name].size() == 0)
            throw std::invalid_argument("Invalid sprite name: '"+name+"'");
        return m_sprites[name][0];
    }

    std::map<Objects::Direction, sf::Sprite> SpriteManager::getCreatureSprites(
        const Objects::CreatureType& type
    ){
        std::map<Objects::CreatureType, std::string> typeToString = {
            {Objects::CreatureType::PLAYER, "player"},
        };
        
        const std::map<Objects::Direction, std::string> directionSuffix = {
            {Objects::DOWN, "_front"},
            {Objects::UP, "_back"},
            {Objects::LEFT, "_left"},
            {Objects::RIGHT, "_right"}
        };
        const Objects::Direction directions[] = {Objects::LEFT, Objects::RIGHT, Objects::UP, Objects::DOWN};

        std::map<Objects::Direction, sf::Sprite> map = {};

        for (Objects::Direction dir : directions) {
            std::string spriteName = typeToString[type] + directionSuffix.at(dir);
            map[dir] = getSprite( spriteName );
        }
        
        return map;
    }

    sf::Sprite SpriteManager::getTileSprite(const Map::TileType &type) {
        std::map<Map::TileType, std::string> typeToString = {
            {Map::TileType::DIRT,  "dirt"},
            {Map::TileType::STONE, "stone"},
            {Map::TileType::GRASS, "grass"},
        };

        return getSprite( typeToString[type] );
    }
}