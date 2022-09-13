#ifndef ANIMATED_CELL_HPP
#define ANIMATED_CELL_HPP

#include "cell.hpp"

namespace Objects {
    namespace Map
    {
        class AnimatedCell : public Cell {
        public:
            AnimatedCell() = delete;
            AnimatedCell(
                const std::string &spriteName, 
                Common::Vector2D<double> position, bool isSolid = true);

            void onUpdate(const sf::Time &elapsedTime) override;
        private:
            double m_frameCounter;
        };
    } // namespace Map
    
} // namespace Objects

#endif