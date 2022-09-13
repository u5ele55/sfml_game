#ifndef STATIC_CELL_HPP
#define STATIC_CELL_HPP

#include "cell.hpp"

namespace Objects {
    namespace Map
    {
        class StaticCell : public Cell {
        public:
            StaticCell() = delete;
            StaticCell(
                const std::string &spriteName, 
                Common::Vector2D<double> position, bool isSolid = true);
        };
    } // namespace Map
    
} // namespace Objects

#endif