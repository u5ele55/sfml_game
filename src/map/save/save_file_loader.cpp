#include "save_file_loader.hpp"

#include "../../utilities/string_utilities.hpp"
#include "../events/test_event_creator.hpp"


namespace Map
{
    SaveFileLoader::SaveFileLoader(const std::string &filename) {
        file.open(filename);
        if (file.fail()) {
            throw Exceptions::LoadingMapException(
                Exceptions::LoadingMapException::Step::Undefined, 
                Exceptions::LoadingMapException::Reason::NoFile);
        }
    }

    SaveFileLoader::~SaveFileLoader() {
        file.close();
    }

    FieldMap SaveFileLoader::loadMap() {
        std::string line;
        bool fieldCreated = false, cellsPlaced = false, playerCreated = false;

        FieldMap result;
        TestEventCreator* eventCreator = new TestEventCreator(result);

        while (std::getline(file, line)) {
            if (!fieldCreated && line.substr(0, 7) == "{Field ") {
                try {
                    auto fSize = StringUtilities::findTwoInts(line);
                    result = FieldMap( fSize.first, fSize.second );
                } catch (...) {
                    throw Exceptions::LoadingMapException(
                        Exceptions::LoadingMapException::Step::FieldCreation, 
                        Exceptions::LoadingMapException::Reason::FileDataIncorrect);
                }
                fieldCreated = true;
            }
            else if (fieldCreated && !cellsPlaced) {
                if (line.substr(0, 8) == "{Player ") {
                    // player
                    cellsPlaced = true;
                    try {
                        auto playerPos = StringUtilities::findTwoInts(line);
                        result.player->position = {playerPos.first, playerPos.second};
                    } catch (...) {
                        throw Exceptions::LoadingMapException(
                            Exceptions::LoadingMapException::Step::PlayerCreation, 
                            Exceptions::LoadingMapException::Reason::FileDataIncorrect);
                    }
                    continue;
                }
                try {
                    auto cellPos = StringUtilities::findTwoInts(line);
                    Cell cell = Cell::fromString(line.substr(line.find('<')), eventCreator);
                    result.setCell(cellPos.first, cellPos.second, cell);
                } catch (...) {
                    throw Exceptions::LoadingMapException(
                        Exceptions::LoadingMapException::Step::CellCreation, 
                        Exceptions::LoadingMapException::Reason::FileDataIncorrect);
                }
            }
            else if (cellsPlaced) {
                try {
                    result.player->creature = Objects::Player::fromSlon(line);
                    playerCreated = true;
                } catch (...) {
                    throw Exceptions::LoadingMapException(
                        Exceptions::LoadingMapException::Step::PlayerCreation, 
                        Exceptions::LoadingMapException::Reason::FileDataIncorrect);
                }
                
            }
        }

        if (!fieldCreated) 
            throw Exceptions::LoadingMapException(
                Exceptions::LoadingMapException::Step::FieldCreation, 
                Exceptions::LoadingMapException::Reason::FileDataIncorrect);
        if (!playerCreated) 
            throw Exceptions::LoadingMapException(
                Exceptions::LoadingMapException::Step::PlayerCreation, 
                Exceptions::LoadingMapException::Reason::FileDataIncorrect);
            
        return result;
    }
} // namespace Map
