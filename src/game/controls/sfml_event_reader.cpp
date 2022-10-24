#include "sfml_event_reader.hpp"
#include "sfml_key_binder.hpp"
#include "event_reader.hpp"

namespace Controls
{
    SfmlEventReader::SfmlEventReader(GameMediator *notifier, ControlsStorage controls) 
        : EventReader<sf::RenderWindow>(notifier, controls) {}

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
} // namespace Controls

