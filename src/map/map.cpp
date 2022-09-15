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
                m_field[i][j] = new StaticCell(TileType::DIRT, {j,i}, false);
            }
        }
        m_field[3][3]->setSolidity(true);
        m_field[3][3]->setTileType(Map::TileType::STONE);

    }

    Cell *FieldMap::get(int x, int y) const {
        if (x < 0) {
            x *= -1;
            x = m_width - x % m_width;
        }
        if (y < 0) {
            y *= -1;
            y = m_height - y % m_height;
        }
        return m_field[y % m_height][x % m_width];
    }

    Cell *FieldMap::get(const Common::Vector2D<int> &position) const {
        return get(position.x, position.y);
    }

    Common::Vector2D<unsigned int> FieldMap::getSize() const { return {m_width, m_height}; }
} // namespace Map
