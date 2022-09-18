#ifndef LEVEL_PAINTER_HPP
#define LEVEL_PAINTER_HPP

#include <SFML/Graphics.hpp>
#include "../objects/player.hpp"
#include "../map/map.hpp"

namespace Graphics
{
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