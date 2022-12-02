#include "save_file_loader.hpp"

#include "../../utilities/string_utilities.hpp"

namespace Map
{
    SaveFileLoader::SaveFileLoader(const std::string &filename) {
        file.open(filename);
        if (file.fail()) {
            throw std::invalid_argument("File with provided name does not exist!");
        }
    }

    SaveFileLoader::~SaveFileLoader() {
        file.close();
    }

    FieldMap SaveFileLoader::loadMap() {
        std::string line;
        bool fieldCreated = false;

        FieldMap result;

        while (std::getline(file, line)) {
            if (!fieldCreated && line.substr(0, 7) == "{Field ") {
                auto fSize = StringUtilities::findTwoInts(line);
                std::cout << fSize.first << " " << fSize.second << '\n';
                result = FieldMap( fSize.first, fSize.second );
                std::cout << result;
                fieldCreated = true;
            }
            else if (fieldCreated) {
                if (line[0] == '{')
                    break;
                auto cellPos = StringUtilities::findTwoInts(line);
                std::cout << cellPos.first << " " << cellPos.second << '\n';
                Cell cell = Cell::fromString(line.substr(line.find('<')));
                result.setCell(cellPos.first, cellPos.second, cell);
            }
        }

        if (!fieldCreated) throw std::runtime_error("Field wasn't created: no field data found in file.");

        return result;
    }
} // namespace Map