#ifndef LEVEL_PAINTER_HPP
#define LEVEL_PAINTER_HPP

#include <SFML/Graphics.hpp>
#include "../objects/player.hpp"

class LevelPainter {
public:
    LevelPainter() = delete;
    static void drawWindow(
        sf::RenderWindow& window, 
        const std::vector<Objects::Creature> &creatures);

};

#endif