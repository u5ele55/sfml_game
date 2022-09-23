#ifndef CHANGE_EVENT_HPP
#define CHANGE_EVENT_HPP

#include "map_event.hpp"
#include "../../common/vector2d.hpp"

namespace Map::Events
{
    struct CellData {
        Common::Vector2D<int> position;
        Cell *cell;
    };
    class ChangeCellsEvent : public MapEvent {
    public:
        ChangeCellsEvent(const ChangeCellsEvent &) = delete;
        ChangeCellsEvent(ChangeCellsEvent&&) = delete;
        ChangeCellsEvent(FieldMap &map, const std::vector<CellData> &newCells);
        void trigger() final;
    private:
        std::vector<CellData> m_newCells;
    };
} // namespace Map::Events

#endif