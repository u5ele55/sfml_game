#ifndef CHOOSE_MAP_DIALOG_HPP
#define CHOOSE_MAP_DIALOG_HPP

class ChooseMapDialog;

#include "../../map/map.hpp"
#include <vector>

namespace Graphics
{
    struct MapTypeButton {
        sf::Sprite sprite;
        Map::MapType type;
    };

    class ChooseMapDialog {
    public:
        ChooseMapDialog();
        Map::MapType showDialog();
    private:
        std::vector<MapTypeButton> m_buttons;
        unsigned int m_width;
        unsigned int m_height;
    };
} // namespace Graphics


#endif