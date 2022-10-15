#include "observable.hpp"

namespace Log
{
    void Observable::subscribe(Observer *observer) {
        for (int i = 0; i < listeners.size(); i ++) 
            if (observer == listeners[i]) {
                return;
            }
        listeners.push_back(observer);
    }
    void Observable::unsubscribe(Observer *observer) {
        for (int i = 0; i < listeners.size(); i ++) 
            if (observer == listeners[i]) {
                listeners.erase(listeners.begin() + i);
                return;
            }
        
    }
    void Observable::copySubscriptions(Observable *other) {
        if (other == nullptr)
            return;
        for (auto *obs : other->listeners) 
            listeners.push_back(obs);
    }
    void Observable::notify(const Message &message) {
        for (Observer *obs : listeners)
            obs->update(message);
    }

} // namespace Log
