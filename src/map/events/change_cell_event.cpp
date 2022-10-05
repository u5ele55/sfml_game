#include "change_cell_event.hpp"

namespace Map::Events
{
    ChangeCellsEvent::ChangeCellsEvent(FieldMap &map, const std::vector<CellData> &newCells) 
        : MapEvent(map), m_newCells(newCells) {}
    
    void ChangeCellsEvent::trigger() {
        for (const auto &newCell : m_newCells) {
            m_map.setCell(newCell.position, newCell.cell);
        }
    }
    ChangeCellsEvent::~ChangeCellsEvent() {}
} // namespace Map::Events
