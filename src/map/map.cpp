#include "map.hpp"
#include "static_cell.hpp"

namespace Map
{
    const int baseHeight = 10;
    const int baseWidth = 20;
    FieldMap::FieldMap() : FieldMap(baseWidth, baseHeight) {}

    FieldMap::FieldMap(unsigned int width, unsigned int height) 
    : m_width(width), m_height(height) 
    {
        m_field = std::vector<std::vector<Cell*>>(
            height,
            std::vector<Cell*>(width, nullptr)
            );
        
        for (int i = 0; i < height; i ++) {
            for (int j = 0; j < width; j ++) {
                auto *c = new StaticCell(TileType::DIRT, {j,i}, false);
                m_field[i][j] = c;
            }
        }
    }

    Cell *FieldMap::get(unsigned int x, unsigned int y) const {
        if (x >= m_width || y >= m_height) return nullptr;
        return m_field[y][x];
    }

    Common::Vector2D<unsigned int> FieldMap::getSize() const { return {m_width, m_height}; }
} // namespace Map
