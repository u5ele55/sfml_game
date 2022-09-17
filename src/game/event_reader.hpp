#ifndef EVENT_READER_HPP
#define EVENT_READER_HPP

class SfmlEventReader;

#include <SFML/Graphics.hpp>
#include "game_mediator.hpp"

class SfmlEventReader {
public:
    SfmlEventReader() = delete;
    SfmlEventReader(GameMediator *notifier);
    void readEvent(sf::RenderWindow &window);
private:
    GameMediator *m_notifier;
    UserEvent keyToEvent(const sf::Keyboard::Key &) const;
};

#endif