#ifndef LEVEL_PAINTER_HPP
#define LEVEL_PAINTER_HPP

#include <SFML/Graphics.hpp>
#include "../objects/player.hpp"
#include "../map/map.hpp"

namespace Graphics
{
    const int CELL_WIDTH = 32;
    const int CELL_HEIGHT = 32;

    const int WINDOW_HEIGHT = 960;
    const int WINDOW_WIDTH = 1280;

    class LevelPainter {
    public:
        LevelPainter(sf::RenderWindow& window);
        void drawWindow(
            const Common::Vector2D<int> &playerPosition,
            const Objects::Player &player,
            const std::vector<Objects::Object> &objects,
            const Map::FieldMap &map
            );
        ~LevelPainter();
    private:
        sf::RenderWindow& window;
        Common::Vector2D<int> prevPlayerPosition;
        sf::View view;
        sf::Font *font;
    };
} // namespace Graphics

#endif