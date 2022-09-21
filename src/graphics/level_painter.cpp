#include "level_painter.hpp"
#include "sprite_manager.hpp"
#include "../map/cell.hpp"

#include <iostream>

namespace Graphics
{
    
    LevelPainter::LevelPainter(sf::RenderWindow& window) 
        : window(window), prevPlayerPosition({-1,-1}) {
            view.setSize(Graphics::WINDOW_WIDTH / 2, Graphics::WINDOW_HEIGHT / 2);
        }

    void LevelPainter::drawWindow(
        const Common::Vector2D<int> &playerPosition,
        const Objects::Player &player,
        const std::vector<Objects::Object> &objects,
        const Map::FieldMap &map) 
    {
        window.clear();
        if (prevPlayerPosition != playerPosition) {
            view.setCenter(
                playerPosition.x * CELL_WIDTH + CELL_WIDTH / 2, 
                playerPosition.y * CELL_HEIGHT + CELL_HEIGHT / 2
                );
            
            window.setView(view);
            prevPlayerPosition = playerPosition;
        }
        
        auto &spriteManager = Graphics::SpriteManager::getInstance();
        const auto mapSize = map.getSize(); 
        for (int i = 0; i < mapSize.y; i++) {
            for (int j = 0; j < mapSize.x; j ++) {
                const Common::Vector2D<int> &cellCoords = map.getCoords(j, i);
                
                sf::Sprite sprite = spriteManager.getTileSprite(map.getCellType(cellCoords));
                sprite.setPosition(
                    cellCoords.x * CELL_WIDTH, 
                    cellCoords.y * CELL_HEIGHT
                    );
                    
                window.draw(sprite);
            }
        }
        
        auto p_sprite = spriteManager.getCreatureSprites(player.getCreatureType())[player.getFacing()];
        p_sprite.setPosition(
            playerPosition.x * CELL_WIDTH,
            playerPosition.y * CELL_HEIGHT
            );    
        window.draw(p_sprite);

        window.display();
    }
} // namespace Graphics
