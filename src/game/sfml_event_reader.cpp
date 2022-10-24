#include "sfml_event_reader.hpp"
#include "controls/sfml_key_binder.hpp"


SfmlEventReader::SfmlEventReader(GameMediator *notifier, Controls::ControlsStorage controls) 
    : m_notifier(notifier), m_controls(controls) {}

void SfmlEventReader::readEvent(sf::RenderWindow &window) {
    sf::Event event;
   
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed) {
            char key = Controls::SfmlKeyBinder::keyToChar(event.key.code);
            m_notifier->notify(m_controls.userEventFromChar(key));
        }

        if (event.type == sf::Event::Closed)
            m_notifier->notify(UserEvent::ESC);
    }
}