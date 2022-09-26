#include "cell.hpp"
#include "../objects/object.hpp"
#include "events/event.hpp"
#include "events/change_cell_event.hpp"

#include <iostream>

namespace Map
{
    FieldMap a;
    Cell::Cell() : Cell(TileType::DIRT) {}
    Cell::Cell(
        TileType type, bool isSolid)
        : m_type(type), m_event(nullptr), m_isSolid(isSolid), Objects::Object() {}
    
    TileType Cell::getTileType() const { return m_type; }
    void Cell::setTileType(const TileType &type) { m_type = type; }

    void Cell::setEvent(Events::Event *event) { 
        m_event = event;
    }

    void Cell::triggerEvent() { 
        if (m_event != nullptr) {
            m_event->trigger(); 
        }
    }
    
    bool Cell::isSolid() {return m_isSolid;}
    void Cell::setSolidity(bool solid) {m_isSolid = solid;}


    Cell::~Cell() {
        delete m_event;
    }
} // namespace Map

