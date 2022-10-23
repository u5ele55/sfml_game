#ifndef CONTROLS_STORAGE_HPP
#define CONTROLS_STORAGE_HPP

#include "user_event.hpp"
#include <vector>
#include <string>

namespace Controls
{
    class ControlsStorage {
    private:
        std::vector<char, UserEvent> m_binds;
        std::pair<char, UserEvent> process(const std::string &line);
    public:
        ControlsStorage();
        ControlsStorage(const std::string &controlsFile);

        UserEvent userEventFromChar(char key) const;
    };
} // namespace Controls


#endif