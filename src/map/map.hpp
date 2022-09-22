#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "cell.hpp"

#define EXISTING_MAP_TYPES 2

namespace Map
{
    enum MapType {
        Overworld, Dungeon
    };

    extern const MapType existingMapTypes[EXISTING_MAP_TYPES];

    class FieldMap  {
    public:
        FieldMap();
        FieldMap(unsigned int width, unsigned int height);
        FieldMap(const FieldMap& other);
        FieldMap(FieldMap&& tmp); // TODO
        FieldMap& operator=(const FieldMap& other); // TODO
        FieldMap& operator=(FieldMap&& other);

        Common::Vector2D<unsigned int> getSize() const;

        /// @brief 
        /// Returns cell on position <x % width, y % height>. 
        /// For example, if width=15, height=10, get(-2, 23) will return
        /// cell on [13, 3].
        /// @return 
        Common::Vector2D<int> getCoords(int x, int y) const;
        /// @brief 
        /// Returns cell on position <x % width, y % height>. 
        /// For example, if width=15, height=10, get(Vector2D(-2, 23)) will return
        /// cell on [13, 3].
        /// @return 
        Common::Vector2D<int> getCoords(const Common::Vector2D<int> &position) const;

        void triggerCellEvent(int x, int y) const;
        void triggerCellEvent(const Common::Vector2D<int> &position) const;

        bool getCellSolidity(int x, int y) const;
        bool getCellSolidity(const Common::Vector2D<int> &position) const;

        TileType getCellType(int x, int y) const;
        TileType getCellType(const Common::Vector2D<int> &position) const;

        ~FieldMap();
    private:
        unsigned int m_width;
        unsigned int m_height;
        std::vector<std::vector<Cell*>> m_field;
    };

} // namespace Map
    
#endif