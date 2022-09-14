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
        Cell *get(unsigned int x, unsigned int y) const;
        Common::Vector2D<unsigned int> getSize() const;
    private:
        unsigned int m_width;
        unsigned int m_height;
        std::vector<std::vector<Cell*>> m_field;
    };

} // namespace Map
    
#endif