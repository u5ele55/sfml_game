#ifndef LEVEL_PAINTER_HPP
#define LEVEL_PAINTER_HPP

#include <SFML/Graphics.hpp>
#include "../objects/player.hpp"
#include "../map/map.hpp"

namespace Graphics
{
    const int cellWidth = 32;
    const int cellHeight = 32;

    const int windowHeight = 1280;
    const int windowWidth = 960;

    class LevelPainter {
    public:
        LevelPainter() = delete;
        static void drawWindow(
            sf::RenderWindow& window, 
            const Common::Vector2D<int> &playerPosition,
            const Objects::Player &player,
            const std::vector<Objects::Object> &objects,
            const Map::FieldMap &map
            );

    };
} // namespace Graphics

#endif