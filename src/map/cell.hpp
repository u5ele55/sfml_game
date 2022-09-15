#ifndef CELL_HPP
#define CELL_HPP

#include "../objects/object.hpp"
#include "events/event.hpp"

namespace Map
{
    enum TileType {
        DIRT, STONE, GRASS
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
        void setEvent(const Events::Event &event);
        void triggerEvent();
    private:
        TileType m_type;
        Events::Event *m_event;
    };
} // namespace Map

#endif