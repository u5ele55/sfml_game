#ifndef EVENT_READER_HPP
#define EVENT_READER_HPP

namespace Controls
{
    template <typename ... T>
    class EventReader; 
}

#include "../game_mediator.hpp"
#include "controls_storage.hpp"

namespace Controls
{
    template <typename ... T>
    class EventReader {
    public:
        EventReader(GameMediator *notifier, ControlsStorage controls);
        
        virtual void readEvent(T& ... args) const = 0;
    protected:
        GameMediator *m_notifier;
        Controls::ControlsStorage m_controls;
    };
} // namespace Controls

#endif