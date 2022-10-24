#ifndef EVENT_READER_HPP
#define EVENT_READER_HPP

class SfmlEventReader;

#include <SFML/Graphics.hpp>
#include "game_mediator.hpp"
#include "controls/controls_storage.hpp"

class SfmlEventReader {
public:
    SfmlEventReader() = delete;
    SfmlEventReader(GameMediator *notifier, Controls::ControlsStorage controls);
    void readEvent(sf::RenderWindow &window);
private:
    GameMediator *m_notifier;
    Controls::ControlsStorage m_controls;
};

#endif