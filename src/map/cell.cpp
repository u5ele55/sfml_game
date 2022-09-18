#include "cell.hpp"
#include "../objects/object.hpp"
namespace Map
{
    Cell::Cell(
        TileType type, bool isSolid)
        : m_type(type), m_event(nullptr), m_isSolid(isSolid), Objects::Object() {}
    
    TileType Cell::getTileType() const { return m_type; }
    void Cell::setTileType(const TileType &type) { m_type = type; }

    void Cell::setEvent(const Events::Event &event) { *m_event = event; }
    void Cell::triggerEvent() { 
        if (m_event != nullptr)
            m_event->trigger(); 
    }
    
    bool Cell::isSolid() {return m_isSolid;}
    void Cell::setSolidity(bool solid) {m_isSolid = solid;}
} // namespace Map

