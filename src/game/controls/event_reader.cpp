#include "event_reader.hpp"

namespace Controls
{
    template<typename T>
    EventReader<T>::EventReader(GameMediator *notifier, ControlsStorage controls)
        : m_controls(controls), m_notifier(notifier) {}

    template class EventReader<sf::RenderWindow>;
} // namespace Controls
