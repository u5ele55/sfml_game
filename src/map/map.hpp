#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "cell.hpp"


namespace Map
{
    class FieldMap  {
    public:
        FieldMap();
        FieldMap(unsigned int width, unsigned int height);

        Common::Vector2D<unsigned int> getSize() const;

        /// @brief 
        /// Returns cell on position <x % width, y % height>. 
        /// For example, if width=15, height=10, get(-2, 23) will return
        /// cell on [13, 3].
        /// @return 
        Common::Vector2D<int> getCoords(int x, int y) const;
        Common::Vector2D<int> getCoords(const Common::Vector2D<int> &position) const;

        void triggerCellEvent(int x, int y) const;
        void triggerCellEvent(const Common::Vector2D<int> &position) const;

        bool getCellSolidity(int x, int y) const;
        bool getCellSolidity(const Common::Vector2D<int> &position) const;

        TileType getCellType(int x, int y) const;
        TileType getCellType(const Common::Vector2D<int> &position) const;
    private:
        unsigned int m_width;
        unsigned int m_height;
        std::vector<std::vector<Cell*>> m_field;
    };

} // namespace Map
    
#endif