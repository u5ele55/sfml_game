#ifndef FILE_MAP_SAVER
#define FILE_MAP_SAVER

#include "map_saver.hpp"

namespace Map
{
    class FileMapSaver : MapSaver {
    public:
        void saveMap(const FieldMap &map, const std::string& saveName) final;
    };
} // namespace Map


#endif