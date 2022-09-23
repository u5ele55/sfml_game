#ifndef MAP_EVENT_HPP
#define MAP_EVENT_HPP

#include "event.hpp"
#include "../map.hpp"

namespace Map::Events
{
    class MapEvent : public Event {
    public:
        MapEvent(FieldMap &);
    protected:
        FieldMap &m_map;
    };

} // namespace Map

#endif