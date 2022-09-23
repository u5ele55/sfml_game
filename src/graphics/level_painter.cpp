#include "level_painter.hpp"
#include "sprite_manager.hpp"
#include "../map/cell.hpp"

#include <iostream>

namespace Graphics
{
    
    LevelPainter::LevelPainter(sf::RenderWindow& window) 
        : window(window), prevPlayerPosition({-1,-1}), font(new sf::Font)
    {
        view.setSize(Graphics::WINDOW_WIDTH / 2, Graphics::WINDOW_HEIGHT / 2);
        
        if (!font->loadFromFile("assets/fonts/PressStart2P.ttf")) {
            throw std::invalid_argument("Invalid font name.");
        }
    }

    void LevelPainter::drawWindow(
        const Common::CreatureWrapper &player,
        const std::vector<Objects::Object> &objects,
        const Map::FieldMap &map) 
    {
        window.clear();
        
        if (prevPlayerPosition != player.position) {
            view.setCenter(
                player.position.x * CELL_WIDTH + CELL_WIDTH / 2, 
                player.position.y * CELL_HEIGHT + CELL_HEIGHT / 2
                );
            
            window.setView(view);
            prevPlayerPosition = player.position;
        }

        sf::Vector2f topLeft = view.getCenter() - sf::Vector2f(view.getSize().x / 2, view.getSize().y / 2);
        
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
        
        auto p_sprite = spriteManager.getCreatureSprites(player.creature.getCreatureType())[player.creature.getFacing()];
        p_sprite.setPosition(
            player.position.x * CELL_WIDTH,
            player.position.y * CELL_HEIGHT
            );    
        window.draw(p_sprite);

        float leftOffset = 10;
        float topOffset = 10;
        sf::Text text;
        text.setFont(*font);
        text.setCharacterSize(14); 

        text.setString("HP: " + std::to_string(player.creature.getHp()) + "/" + std::to_string(player.creature.getMaxHp()));
        text.setPosition(topLeft + sf::Vector2f(leftOffset, topOffset));
        window.draw(text);

        text.setString("Mana: " + std::to_string(player.creature.getMana()) + "/" + std::to_string(player.creature.getMaxMana()));
        text.setPosition(topLeft + sf::Vector2f(leftOffset, topOffset + text.getLocalBounds().height));
        window.draw(text);

        // text.setString("Melee DMG: " + std::to_string(player.getMeleeAttack()));
        // text.setPosition(topLeft + sf::Vector2f(leftOffset, topOffset + text.getLocalBounds().height * 2));
        // window.draw(text);

        // text.setString("Magic DMG: " + std::to_string(player.getMageAttack()));
        // text.setPosition(topLeft + sf::Vector2f(leftOffset, topOffset + text.getLocalBounds().height * 3));
        // window.draw(text);
        
        window.display();
    }

    LevelPainter::~LevelPainter() {
        delete font;
    }
} // namespace Graphics
