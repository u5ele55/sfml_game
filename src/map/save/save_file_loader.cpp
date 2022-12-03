#include "save_file_loader.hpp"

#include "../../utilities/string_utilities.hpp"
#include "../events/test_event_creator.hpp"

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
        bool fieldCreated = false, cellsPlaced = false;

        FieldMap result;
        TestEventCreator* eventCreator = new TestEventCreator(result);

        while (std::getline(file, line)) {
            if (!fieldCreated && line.substr(0, 7) == "{Field ") {
                auto fSize = StringUtilities::findTwoInts(line);
                result = FieldMap( fSize.first, fSize.second );
                std::cout << result;
                fieldCreated = true;
            }
            else if (fieldCreated && !cellsPlaced) {
                if (line[0] == '{') {
                    // player
                    std::cout << "PP";
                    cellsPlaced = true;
                    auto playerPos = StringUtilities::findTwoInts(line);
                    std::cout << "Layer"; 
                    result.player->position = {playerPos.first, playerPos.second};
                    std::cout << "Position";
                    continue;
                }
                auto cellPos = StringUtilities::findTwoInts(line);
                Cell cell = Cell::fromString(line.substr(line.find('<')), eventCreator);
                result.setCell(cellPos.first, cellPos.second, cell);
            }
            else if (cellsPlaced) {
                std::cout << " go ";
                result.player->creature = Objects::Player::fromSlon(line);
                std::cout << result.player->creature;
            }
        }

        if (!fieldCreated) throw std::runtime_error("Field wasn't created: no field data found in file.");

        return result;
    }
} // namespace Map
