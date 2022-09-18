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
                m_field[i][j] = new StaticCell(TileType::DIRT, false);
            }
        }
        for (int i = 0; i < width; i ++) {
            m_field[0][i]->setTileType(Map::TileType::GRASS);
            m_field[1][i]->setTileType(Map::TileType::GRASS);
        }

        for (int i = 0; i < width/2; i ++) {
            m_field[5][i]->setSolidity(true);
            m_field[5][i]->setTileType(Map::TileType::STONE);
        }
        

    }

    Common::Vector2D<int> FieldMap::getCoords(int x, int y) const {
        if (x < 0) {
            x *= -1;
            x = m_width - x % m_width;
        }
        if (y < 0) {
            y *= -1;
            y = m_height - y % m_height;
        }
        return {x % static_cast<int>(m_width), y % static_cast<int>(m_height)};
    }

    Common::Vector2D<int> FieldMap::getCoords(const Common::Vector2D<int> &position) const {
        return getCoords(position.x, position.y);
    }

    void FieldMap::triggerCellEvent(int x, int y) const {
        const auto &pos = getCoords(x,y);
        m_field[pos.y][pos.x]->triggerEvent();
    }
    void FieldMap::triggerCellEvent(const Common::Vector2D<int> &position) const {
        triggerCellEvent(position.x, position.y);
    }

    bool FieldMap::getCellSolidity(int x, int y) const {
        const auto &pos = getCoords(x,y);
        return m_field[pos.y][pos.x]->isSolid();
    }
    bool FieldMap::getCellSolidity(const Common::Vector2D<int> &position) const {
        return getCellSolidity(position.x, position.y);
    }

    TileType FieldMap::getCellType(int x, int y) const {
        const auto &pos = getCoords(x,y);
        return m_field[pos.y][pos.x]->getTileType();
    }
    TileType FieldMap::getCellType(const Common::Vector2D<int> &position) const {
        return getCellType(position.x, position.y);
    }

    Common::Vector2D<unsigned int> FieldMap::getSize() const { return {m_width, m_height}; }



    FieldMap::~FieldMap() {
        for (int i = 0 ; i < m_field.size(); i ++) {
            for(int j = 0; j < m_field[i].size(); j ++)
                delete m_field[i][j];
        }
    }
} // namespace Map
