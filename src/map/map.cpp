#include "map.hpp"

#include <iostream>

#include "../log/console_logger.hpp"

namespace Map
{
    const MapType existingMapTypes[EXISTING_MAP_TYPES] = {
        MapType::Overworld, MapType::Dungeon
    };

    const int baseHeight = 15;
    const int baseWidth = 15;
    FieldMap::FieldMap() : FieldMap(baseWidth, baseHeight) {}

    FieldMap::FieldMap(unsigned int width, unsigned int height) 
    : m_width(width), m_height(height) 
    {
        if (m_width > 200 || m_height > 200 ||  m_height < 6) {
            notify(Log::Message(Log::LogType::CriticalState, "Field initialized with wrong sizes"));
            throw std::invalid_argument("Sizes of a map must be positive and less than 200, also height should be at least 6!");
        }
        m_field = std::vector<std::vector<Cell>>(
            height,
            std::vector<Cell>(width, Cell())
            );
        
        for (int i = 0; i < height; i ++) {
            for (int j = 0; j < width; j ++) {
                m_field[i][j] = Cell(TileType::DIRT, false);
            }
        }
        for (int i = 0; i < width; i ++) {
            if (i & 1)
            m_field[0][i].setTileType(Map::TileType::GRASS);
            else
            m_field[1][i].setTileType(Map::TileType::GRASS);
        }

        for (int i = 0; i < width/2; i ++) {
            m_field[5][i].setSolidity(true);
            m_field[5][i].setTileType(Map::TileType::STONE);
        }
    }

    FieldMap::FieldMap(const FieldMap& other) : m_height(other.m_height), m_width(other.m_width) {
        m_field = std::vector< std::vector<Map::Cell> >(
            m_height, std::vector<Map::Cell>(m_width, Cell())
            );
        for (int i = 0 ; i < m_height; i ++) 
            for(int j = 0 ; j < m_width; j ++) {
                m_field[i][j] = other.m_field[i][j].copy();
            }
    }

    FieldMap::FieldMap(FieldMap&& other) : m_height(other.m_height), m_width(other.m_width) {
        m_field = std::vector< std::vector<Map::Cell> >(
            m_height, std::vector<Map::Cell>(m_width, Cell())
            );
        
        for (int i = 0 ; i < m_height; i ++) 
            for(int j = 0 ; j < m_width; j ++) {
                std::swap(m_field[i][j], other.m_field[i][j]);
            }
    }

    FieldMap& FieldMap::operator=(const FieldMap& other) {
        if (this != &other) {
            m_height = other.m_height;
            m_width = other.m_width;
            m_field.clear();
            std::vector<Map::Cell> row;
            for (int i = 0 ; i < m_height; i ++) {
                m_field.push_back(row);
                for(int j = 0 ; j < m_width; j ++) {
                    m_field[i].push_back(other.m_field[i][j].copy());
                }
            }
        }
        return *this;
    }

    FieldMap& FieldMap::operator=(FieldMap &&other) {
        if (this != &other) {
            m_height = other.m_height;
            m_width = other.m_width;

            m_field.clear();
            
            for (int i = 0 ; i < m_height; i ++) {
                m_field.push_back(std::vector<Map::Cell>(m_width, Cell()));
                for(int j = 0 ; j < m_width; j ++) {
                    std::swap(m_field[i][j], other.m_field[i][j]);
                }
            }
        }
        return *this;
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

    void FieldMap::triggerCellEvent(int x, int y) {
        const auto &pos = getCoords(x,y);
        m_field[pos.y][pos.x].triggerEvent();
    }
    void FieldMap::triggerCellEvent(const Common::Vector2D<int> &position) {
        triggerCellEvent(position.x, position.y);
    }

    bool FieldMap::getCellSolidity(int x, int y) const {
        const auto &pos = getCoords(x,y);
        return m_field[pos.y][pos.x].isSolid();
    }
    bool FieldMap::getCellSolidity(const Common::Vector2D<int> &position) const {
        return getCellSolidity(position.x, position.y);
    }

    TileType FieldMap::getCellType(int x, int y) const {
        const auto &pos = getCoords(x,y);
        return m_field[pos.y][pos.x].getTileType();
    }
    TileType FieldMap::getCellType(const Common::Vector2D<int> &position) const {
        return getCellType(position.x, position.y);
    }

    Common::Vector2D<unsigned int> FieldMap::getSize() const { return Common::Vector2D<unsigned int>{m_width, m_height}; }

    void FieldMap::setCell(int x, int y, const Cell &cell) {
        const auto &pos = getCoords(x,y);
        m_field[pos.y][pos.x] = cell.copy();
    }
    void FieldMap::setCell(const Common::Vector2D<int> &position, const Cell &cell) {
        setCell(position.x, position.y, cell);
    }

    void FieldMap::setCellEvent(int x, int y, Events::Event *event) {
        const auto &pos = getCoords(x,y);
        m_field[pos.y][pos.x].setEvent(event);
    }
    void FieldMap::setCellEvent(const Common::Vector2D<int> &position, Events::Event *event) {
        setCellEvent(position.x, position.y, event);
    }


    FieldMap::~FieldMap() {
    }
} // namespace Map
