#include "level_painter.hpp"
#include "../graphics/sprite_manager.hpp"
#include "../map/cell.hpp"
#include <iostream>

void LevelPainter::drawWindow(
    sf::RenderWindow& window, 
    const std::vector<Objects::Creature> &creatures) 
{
    window.clear();
	auto &spriteManager = Graphics::SpriteManager::getInstance();
    for (auto cr : creatures) {
        
        auto spriteMap = spriteManager.getCreatureSprites(cr.getCreatureType());
        auto sprite = spriteMap[cr.getFacing()];
        sprite.setPosition(cr.getPosition().x * Objects::Map::cellWidth, cr.getPosition().y * Objects::Map::cellHeight);
        window.draw(sprite);
        
    }

    window.display();
}