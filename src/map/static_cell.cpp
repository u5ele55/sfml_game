#include "static_cell.hpp"

namespace Objects {
    namespace Map
    {
        StaticCell::StaticCell(
            Common::Vector2D<double> position, bool isSolid)
            : Cell(position, isSolid) {}
    } // namespace Map
    
} // namespace Objects
