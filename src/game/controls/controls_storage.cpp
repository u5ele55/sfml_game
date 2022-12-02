#include "controls_storage.hpp"
#include <fstream>
#include <map>
#include <vector>
#include <iostream>

namespace Controls
{
    /// @brief 
    /// Standart configuration (WASD E Q)
    ControlsStorage::ControlsStorage() {
        std::vector<std::string> config = {
            "up: w", "down: s", "right: d", "left: a", "use: e", "esc: q", "load: l", "save: m"
        };
        for (std::string line : config) {
            auto p = process(line);
            m_binds[p.first] = p.second;
        }
    }
    /// @brief Takes configuration from specified file.
    /// Throws std::invalid_argument if file does not exist
    /// @param controlsFile 
    ControlsStorage::ControlsStorage(const std::string &controlsFile) {
        std::ifstream file;
        file.open(controlsFile);

        if (file.fail()) {
            throw std::invalid_argument("Specified file does not exist!");
        }

        for( std::string line; getline( file, line ); ){
            auto p = process(line);
            m_binds[p.first] = p.second;
        }

        file.close();
    }

    UserEvent ControlsStorage::userEventFromChar(char key) const {
        if (m_binds.count(key))
            return m_binds.at(key);
            
        return UserEvent::NONE;
    } 

    std::pair<char, UserEvent> ControlsStorage::process(const std::string &line) {

        std::map<std::string, UserEvent> decoding = {
            {"up", UserEvent::UP},
            {"down", UserEvent::DOWN},
            {"right", UserEvent::RIGHT},
            {"left", UserEvent::LEFT},
            {"use", UserEvent::USE},
            {"esc", UserEvent::ESC},
            {"load", UserEvent::LOAD_GAME},
            {"save", UserEvent::SAVE_GAME}
        }; 

        std::string name = "";
        UserEvent ans;
        int divIndex = -1;

        for (int i = 0; i < line.size(); i ++) {
            if (line[i] == ':')
                if (decoding.count(name)) {
                    ans = decoding[name];
                    divIndex = i;
                    break;
                }
            
            name += std::tolower(line[i]);
        }

        if (divIndex == -1)
            return {0, UserEvent::NONE};
        
        for (int i = divIndex+1; i < line.size(); i ++) 
            if (line[i] != ' ') {
                return {std::tolower(line[i]), ans};
            }
            
        return {0, UserEvent::NONE};
    }
} // namespace Controls
