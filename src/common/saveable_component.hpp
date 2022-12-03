#ifndef SAVEABLE_COMPONENT_HPP
#define SAVEABLE_COMPONENT_HPP

#include <sstream>

// Composite pattern

class SaveableComponent {
public:
    virtual std::string toSlon() const = 0;
};

#endif