#include "sfml_key_binder.hpp"

namespace Controls
{
    /// @brief 
    /// Returns lowercase char
    /// @return 
    char SfmlKeyBinder::keyToChar(sf::Keyboard::Key key) {
        std::map<sf::Keyboard::Key, char> m_binds = {
            {sf::Keyboard::A, 'a'},
            {sf::Keyboard::B, 'b'},
            {sf::Keyboard::C, 'c'},
            {sf::Keyboard::D, 'd'},
            {sf::Keyboard::E, 'e'},
            {sf::Keyboard::F, 'f'},
            {sf::Keyboard::G, 'g'},
            {sf::Keyboard::H, 'h'},
            {sf::Keyboard::I, 'i'},
            {sf::Keyboard::J, 'j'},
            {sf::Keyboard::K, 'k'},
            {sf::Keyboard::L, 'l'},
            {sf::Keyboard::M, 'm'},
            {sf::Keyboard::N, 'n'},
            {sf::Keyboard::O, 'o'},
            {sf::Keyboard::P, 'p'},
            {sf::Keyboard::Q, 'q'},
            {sf::Keyboard::R, 'r'},
            {sf::Keyboard::S, 's'},
            {sf::Keyboard::T, 't'},
            {sf::Keyboard::U, 'u'},
            {sf::Keyboard::V, 'v'},
            {sf::Keyboard::W, 'w'},
            {sf::Keyboard::X, 'x'},
            {sf::Keyboard::Y, 'y'},
            {sf::Keyboard::Z, 'z'}
        };

        if (m_binds.count(key))
            return m_binds.at(key);
        return '*';
    }
} // namespace Controle
