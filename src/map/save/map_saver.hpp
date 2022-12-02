#ifndef MAP_SAVER
#define MAP_SAVER

#include "../map.hpp"

namespace Map
{
    class MapSaver {
    public:
        virtual void saveMap(const FieldMap& map, const std::string& saveName) = 0;
    };
} // namespace Map


#endif