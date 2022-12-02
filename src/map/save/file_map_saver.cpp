#include "file_map_saver.hpp"
#include <fstream>

namespace Map
{
    void FileMapSaver::saveMap(const FieldMap &map, const std::string& saveName) {
        std::ofstream file(saveName + ".txt");
        file << map.toString();
        file.close();
    }
} // namespace Map
