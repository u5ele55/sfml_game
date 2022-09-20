#include "static_cell.hpp"

namespace Map
{
    StaticCell::StaticCell(TileType type, bool isSolid)
        : Cell(type, isSolid) {}

        
    StaticCell::StaticCell(const StaticCell &other) : Cell(other.m_type, other.m_isSolid) {
        *m_event = *other.m_event;
    }
} // namespace Map

