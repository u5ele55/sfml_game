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
        Cell( TileType type, bool isSolid = false);
        TileType getTileType() const;
        void setTileType(const TileType&);
        void setEvent(const Events::Event &event);
        void triggerEvent();

        bool isSolid();
        void setSolidity(bool solid);

        ~Cell();
    protected:
        TileType m_type;
        bool m_isSolid;
        Events::Event *m_event;
    };
} // namespace Map

#endif