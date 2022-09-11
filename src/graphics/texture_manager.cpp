#include "texture_manager.hpp"
#include <iostream>

const Graphics::TextureType Graphics::existingTypes[TEXTURE_TYPES_EXIST] = {
    Graphics::Tile, Graphics::Player
};

Graphics::TextureManager::TextureManager() {
    for( const auto type : Graphics::existingTypes ) {
        sf::Texture *texture = new sf::Texture;
        if (texture->loadFromFile(getAssetName(type)))
            m_textures[type] = texture;
        else 
            std::cout << "ASDASD";
    }
}

Graphics::TextureManager& Graphics::TextureManager::getInstance() {
    static TextureManager textureManager;
    return textureManager;
}
std::string Graphics::TextureManager::getAssetName(const Graphics::TextureType& type) {
    std::string name = "";
    std::string path = "assets/textures/";
    std::map<Graphics::TextureType, std::string> typeToAsset = {
        {Graphics::Tile, "tiles1.png"},
        {Graphics::Player, "player.png"}
        };
    
    if (typeToAsset.count(type) != 0)
        name = typeToAsset[type];

    return path+name;
}

sf::Texture* Graphics::TextureManager::getTexture(const TextureType &type) {
    if (m_textures.count(type) == 0) 
        throw std::invalid_argument("Invalid type");
    
    return m_textures[type];
}