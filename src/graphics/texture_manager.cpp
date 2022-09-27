#include "texture_manager.hpp"
#include <iostream>

namespace Graphics
{
    
const TextureType existingTypes[TEXTURE_TYPES_EXIST] = {
    TextureType::Tile, TextureType::Player, TextureType::Button
};

TextureManager::TextureManager() {
    for( const auto type : existingTypes ) {
        sf::Texture *texture = new sf::Texture;
        if (texture->loadFromFile(getAssetName(type)))
            m_textures[type] = texture;
        else 
            std::cout << "Couldn't load asset: " << getAssetName(type) << "\n";
    }
}

TextureManager& TextureManager::getInstance() {
    static TextureManager textureManager;
    return textureManager;
}
std::string TextureManager::getAssetName(const TextureType& type) {
    std::string name = "";
    std::string path = "assets/textures/";
    std::map<TextureType, std::string> typeToAsset = {
        {TextureType::Tile, "tiles-pipo.png"},
        {TextureType::Player, "player.png"},
        {TextureType::Button, "buttons.png"}
        };
    
    if (typeToAsset.count(type) != 0)
        name = typeToAsset[type];

    return path+name;
}

sf::Texture* TextureManager::getTexture(const TextureType &type) {
    if (m_textures.count(type) == 0) 
        throw std::invalid_argument("Invalid type");
    
    return m_textures[type];
}
} // namespace Graphics
