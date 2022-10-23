#ifndef SFML_KEY_BINDER
#define SFML_KEY_BINDER

#include <map>
#include <SFML/Graphics.hpp>

namespace Controls
{
    class SfmlKeyBinder {
    public:
        static char keyToChar(sf::Keyboard::Key key);
    };
} // namespace Controls


#endif