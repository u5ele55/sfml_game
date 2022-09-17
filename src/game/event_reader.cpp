#include "event_reader.hpp"

SfmlEventReader::SfmlEventReader(GameMediator *notifier) : m_notifier(notifier) {}

void SfmlEventReader::readEvent(sf::RenderWindow &window) {
    sf::Event event;
   
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed) {
            m_notifier->notify(keyToEvent(event.key.code));
        }

        if (event.type == sf::Event::Closed)
            m_notifier->notify(ESC);
    }
}

UserEvent SfmlEventReader::keyToEvent(const sf::Keyboard::Key &key) const {
    std::map<sf::Keyboard::Key, UserEvent> sfEventsToUserEvents = {
        {sf::Keyboard::Escape, ESC},
        {sf::Keyboard::W, UP},
        {sf::Keyboard::A, LEFT},
        {sf::Keyboard::S, DOWN},
        {sf::Keyboard::D, RIGHT},
        {sf::Keyboard::W, UP},
        
    };

    if (sfEventsToUserEvents.count(key) == 0)
        return NONE;
    return sfEventsToUserEvents[key];
}