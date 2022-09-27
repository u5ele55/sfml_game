#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <map>
#include <SFML/Graphics.hpp>

#define TEXTURE_TYPES_EXIST 3

namespace Graphics {

    enum class TextureType {
        Tile,
        Player,
        Enemy,
        Item,
        Button
    };
    extern const TextureType existingTypes[TEXTURE_TYPES_EXIST];

    class TextureManager {
    public:
        TextureManager(const TextureManager&) = delete;
        TextureManager(TextureManager&&) = delete;
        TextureManager& operator=(const TextureManager&) = delete;
        TextureManager& operator=(TextureManager&&) = delete;

        static TextureManager& getInstance();
        sf::Texture* getTexture(const TextureType& type);
        
    private:
        TextureManager();

        std::string getAssetName(const TextureType&);

        std::map<TextureType, sf::Texture*> m_textures;
    };
}
#endif