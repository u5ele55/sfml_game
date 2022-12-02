#ifndef SAVE_LOADER_HPP 
#define SAVE_LOADER_HPP

#include <fstream>
#include "../map.hpp"

namespace Map
{
    class SaveLoader {
    public:
        virtual FieldMap loadMap() = 0;
    };
} // namespace Map


#endif