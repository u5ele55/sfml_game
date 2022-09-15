#include "cell.hpp"
#include "../objects/object.hpp"
namespace Map
{
    Cell::Cell(
        TileType type,
        Common::Vector2D<int> position, bool isSolid)
        : m_type(type), Objects::Object(position, isSolid) {}
    
    TileType Cell::getTileType() const { return m_type; }
    void Cell::setTileType(const TileType &type) { m_type = type; }

    void Cell::setEvent(const Events::Event &event) { *m_event = event; }
    void Cell::triggerEvent() { m_event->trigger(); }
} // namespace Map

