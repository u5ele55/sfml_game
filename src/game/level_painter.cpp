#include "level_painter.hpp"
#include "../graphics/sprite_manager.hpp"
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
        sprite.setPosition(cr.getPosition().x, cr.getPosition().y);
        window.draw(sprite);
        
    }

    window.display();
}