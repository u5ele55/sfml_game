#include "level_painter.hpp"
#include "sprite_manager.hpp"
#include "../map/cell.hpp"

void Graphics::LevelPainter::drawWindow(
    sf::RenderWindow& window, 
    const std::vector<Objects::Creature> &creatures,
    const int &playerIndex,
    const std::vector<Objects::Object> &objects,
    const Map::FieldMap &map) 
{
    window.clear();
    
	auto &spriteManager = Graphics::SpriteManager::getInstance();
    
    const auto mapSize = map.getSize();
    for (int i = 0; i < mapSize.y; i++) {
        for (int j = 0; j < mapSize.x; j ++) {
            const Map::Cell *cell = map.get(j, i);
            const Common::Vector2D<int> &pos = cell->getPosition();
            sf::Sprite sprite = spriteManager.getTileSprite(cell->getTileType());
            sprite.setPosition(
                pos.x * Map::cellWidth, 
                pos.y * Map::cellHeight
                );
            window.draw(sprite);
        }
    }
    
    for (auto cr : creatures) {
        auto spriteMap = spriteManager.getCreatureSprites(cr.getCreatureType());
        sf::Sprite sprite = spriteMap[cr.getFacing()];
        sprite.setPosition(
            cr.getPosition().x * Map::cellWidth, 
            cr.getPosition().y * Map::cellHeight
            );
        window.draw(sprite);
    }

    const Common::Vector2D<int> &playerPosition = creatures[playerIndex].getPosition();  
    sf::View view;
    view.setCenter(
        playerPosition.x * Map::cellWidth + Map::cellWidth / 2, 
        playerPosition.y * Map::cellHeight + Map::cellHeight / 2
        );
    view.setSize(window.getSize().x / 2, window.getSize().y / 2);
    window.setView(view);

    window.display();
}