#include "cell.hpp"

namespace Objects {
    namespace Map
    {
        Cell::Cell(
            
            Common::Vector2D<double> position, bool isSolid)
            : Object(position, isSolid) {}
    } // namespace Map
    
} // namespace Objects
