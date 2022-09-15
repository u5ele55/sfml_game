#ifndef LEVEL_PAINTER_HPP
#define LEVEL_PAINTER_HPP

#include <SFML/Graphics.hpp>
#include "../objects/player.hpp"
#include "../map/map.hpp"

class LevelPainter {
public:
    LevelPainter() = delete;
    static void drawWindow(
        sf::RenderWindow& window, 
        const std::vector<Objects::Creature> &creatures,
        const int &playerIndex,
        const std::vector<Objects::Object> &objects,
        const Map::FieldMap &map
        );

};

#endif