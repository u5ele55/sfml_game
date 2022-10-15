#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include "observer.hpp"
#include <vector>

namespace Log
{
    class Observable {
    public:
        void subscribe(Observer *observer);
        void unsubscribe(Observer *observer);
        void notify(const Message &message);
        void copySubscriptions(Observable *other);
    private:
        std::vector< Observer * > listeners;
    };
} // namespace Log


#endif