#include "sfml_event_reader.hpp"

SfmlEventReader::SfmlEventReader(GameMediator *notifier) : m_notifier(notifier) {}

void SfmlEventReader::readEvent(sf::RenderWindow &window) {
    sf::Event event;
   
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed) {
            m_notifier->notify(keyToEvent(event.key.code));
        }

        if (event.type == sf::Event::Closed)
            m_notifier->notify(UserEvent::ESC);
    }
}

UserEvent SfmlEventReader::keyToEvent(const sf::Keyboard::Key &key) const {
    std::map<sf::Keyboard::Key, UserEvent> sfEventsToUserEvents = {
        {sf::Keyboard::Escape, UserEvent::ESC},

        {sf::Keyboard::W, UserEvent::UP},
        {sf::Keyboard::A, UserEvent::LEFT},
        {sf::Keyboard::S, UserEvent::DOWN},
        {sf::Keyboard::D, UserEvent::RIGHT},
        
        {sf::Keyboard::E, UserEvent::USE},
        
    };

    if (sfEventsToUserEvents.count(key) == 0)
        return UserEvent::NONE;
        
    return sfEventsToUserEvents[key];
}