#ifndef CELL_HPP
#define CELL_HPP

#include "../objects/object.hpp"
#include "events/event.hpp"
#include <iostream>

namespace Map
{
    enum class TileType {
        DIRT, STONE, GRASS
    };

    class Cell : public Objects::Object {
    public:
        Cell();
        Cell( TileType type, bool isSolid = false);
        TileType getTileType() const;
        Events::Event *getEvent() const;
        void setTileType(const TileType&);
        void setEvent(Events::Event *event);
        void triggerEvent();

        bool isSolid() const;
        bool hasEvent() const;
        void setSolidity(bool solid);
        Cell copy() const;

        friend std::ostream &operator<<(std::ostream &stream, const Cell &cell);

        ~Cell();
    protected:
        TileType m_type;
        bool m_isSolid;
        Events::Event *m_event;
    };
} // namespace Map

#endif