#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "message.hpp"

namespace Log
{
    class Observer {
    public:
        virtual void update(const Message &msg) = 0;
    };
} // namespace Log


#endif