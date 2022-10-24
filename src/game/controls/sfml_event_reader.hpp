#ifndef SFML_EVENT_READER_HPP
#define SFML_EVENT_READER_HPP

#include <SFML/Graphics.hpp>
#include "event_reader.hpp"

namespace Controls
{
    class SfmlEventReader : public EventReader<sf::RenderWindow> {
    public:
        SfmlEventReader() = delete;
        SfmlEventReader(GameMediator *notifier, Controls::ControlsStorage controls);
        void readEvent(sf::RenderWindow &window);
    };
} // namespace Controls

#endif