#ifndef STATIC_CELL_HPP
#define STATIC_CELL_HPP

#include "cell.hpp"

namespace Map
{
    class StaticCell : public Cell {
    public:
        StaticCell() = delete;
        StaticCell(TileType type,
            Common::Vector2D<int> position, bool isSolid = true);
    };
} // namespace Map
    
#endif