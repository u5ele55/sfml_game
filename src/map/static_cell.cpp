#include "static_cell.hpp"

namespace Map
{
    StaticCell::StaticCell(TileType type,
        Common::Vector2D<int> position, bool isSolid)
        : Cell(type, position, isSolid) {}
} // namespace Map

