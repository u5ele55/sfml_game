#ifndef STATIC_CELL_HPP
#define STATIC_CELL_HPP

#include "cell.hpp"

namespace Map
{
    class StaticCell : public Cell {
    public:
        StaticCell() = delete;
        StaticCell(const StaticCell &other);
        StaticCell(TileType type, bool isSolid = true);
    };
} // namespace Map
    
#endif