#ifndef CELL_HPP
#define CELL_HPP

#include "../objects/object.hpp"

namespace Map
{
    enum TileType {
        DIRT, STONE
    };
    const int cellWidth = 32;
    const int cellHeight = 32;

    class Cell : public Objects::Object {
    public:
        Cell() = delete;
        Cell( TileType type,
            Common::Vector2D<int> position, bool isSolid = false);
        TileType getTileType() const;
        void setTileType(const TileType&);
    private:
        TileType m_type;
    };
} // namespace Map

#endif