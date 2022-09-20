#include "level_painter.hpp"
#include "sprite_manager.hpp"
#include "../map/cell.hpp"

#include <iostream>

void Graphics::LevelPainter::drawWindow(
    sf::RenderWindow& window, 
    const Common::Vector2D<int> &playerPosition,
    const Objects::Player &player,
    const std::vector<Objects::Object> &objects,
    const Map::FieldMap &map) 
{
    window.clear();
    
	auto &spriteManager = Graphics::SpriteManager::getInstance();
    const auto mapSize = map.getSize(); 
    for (int i = 0; i < mapSize.y; i++) {
        for (int j = 0; j < mapSize.x; j ++) {
            const Common::Vector2D<int> &cellCoords = map.getCoords(j, i);
            
            sf::Sprite sprite = spriteManager.getTileSprite(map.getCellType(cellCoords));
            sprite.setPosition(
                cellCoords.x * Map::cellWidth, 
                cellCoords.y * Map::cellHeight
                );
                
            window.draw(sprite);
        }
    }
    
    auto p_sprite = spriteManager.getCreatureSprites(player.getCreatureType())[player.getFacing()];
    p_sprite.setPosition(
        playerPosition.x * Map::cellWidth,
        playerPosition.y * Map::cellHeight
        );
        
    window.draw(p_sprite);

    sf::View view;
    view.setCenter(
        playerPosition.x * Map::cellWidth + Map::cellWidth / 2, 
        playerPosition.y * Map::cellHeight + Map::cellHeight / 2
        );
    view.setSize(window.getSize().x / 2, window.getSize().y / 2);
    window.setView(view);

    window.display();
}