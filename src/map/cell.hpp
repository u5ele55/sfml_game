#ifndef CELL_HPP
#define CELL_HPP

#include "../objects/object.hpp"

namespace Objects {
    namespace Map
    {
        const int cellWidth = 32;
        const int cellHeight = 32;
        class Cell : public Object {
        public:
            Cell() = delete;
            Cell(
                Common::Vector2D<double> position, bool isSolid = true);
        };
    } // namespace Map
}

#endif