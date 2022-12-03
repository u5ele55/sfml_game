#include "cell.hpp"
#include "../objects/object.hpp"
#include "events/event.hpp"
#include "events/change_cell_event.hpp"
#include "../utilities/string_utilities.hpp"

#include <iostream>
#include <sstream>

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
    std::string Cell::toSlon() const {
        std::stringstream stream;
        stream << "<Cell type={" << (int)getTileType() << "} solid={" << isSolid() 
               << "} contains_event={" << (m_event == nullptr ? "null" : m_event->toSlon()) << "}" << ">";
        return stream.str();
    }

    Cell Cell::fromString(const std::string& data, EventCreator* eventCreator) {
        auto mp = StringUtilities::slonToMap(data);
        Cell obj;
        obj.m_isSolid = mp["solid"] == "1";
        obj.m_type = static_cast<TileType>(stoi(mp["type"]));
        obj.m_event = eventCreator->fromSlon( mp["contains_event"] );
        
        return obj;
    }

    std::ostream &operator<<(std::ostream &stream, const Cell &cell) {
        stream << cell.toSlon();

        return stream;
    }
} // namespace Map

