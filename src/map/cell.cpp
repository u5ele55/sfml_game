#include "cell.hpp"
#include "../objects/object.hpp"
#include "events/event.hpp"
#include "events/change_cell_event.hpp"

#include <iostream>

namespace Map
{
    Cell::Cell() : Cell(TileType::DIRT) {}
    Cell::Cell(TileType type, bool isSolid)
        : m_type(type), m_event(nullptr), m_isSolid(isSolid), Objects::Object() {}
    
    TileType Cell::getTileType() const { return m_type; }
    void Cell::setTileType(const TileType &type) { m_type = type; }

    void Cell::setEvent(Events::Event *event) { 
        m_event = event;
    }

    Events::Event *Cell::getEvent() const {
        return m_event;
    }

    void Cell::triggerEvent() { 
        if (hasEvent()) {
            m_event->trigger(); 
        }
    }

    bool Cell::hasEvent() const {
        return m_event != nullptr;
    }
    
    bool Cell::isSolid() const {return m_isSolid;}
    void Cell::setSolidity(bool solid) {m_isSolid = solid;}
    Cell Cell::copy() const {
        Cell a;
        
        a.setTileType(m_type);
        a.setSolidity(m_isSolid);
        a.setEvent(m_event);
        
        return a;
    }

    Cell::~Cell() {}

    std::ostream &operator<<(std::ostream &stream, const Cell &cell) {

        stream << "<Cell type=" << (int)cell.getTileType() << " solid=" << cell.isSolid() 
               << " contains_event=" << !(cell.getEvent() == nullptr) << ">";

        return stream;
    }
} // namespace Map

