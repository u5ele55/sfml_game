#include "file_map_saver.hpp"
#include <fstream>
#include "../../utilities/string_utilities.hpp"

namespace Map
{
    void FileMapSaver::saveMap(const FieldMap &map, const std::string& saveName) {
        std::ofstream file(saveName + ".txt");
        std::string slon = map.toSlon();
        file << StringUtilities::hash(slon) << "\n";
        file << slon;
        file.close();
    }
} // namespace Map
