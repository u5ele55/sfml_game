#include "object.hpp"
#include <iostream>

namespace Objects{
    Object::Object() 
        : Object({0,0}) {}

    Object::Object(
        Common::Vector2D<int> position, 
        bool isSolid
        ) : m_position(position), m_isSolid(isSolid) {}

    void Object::onInteraction(const Object&) {}

    void Object::setSolidity(bool isSolid) {
        m_isSolid = isSolid;
    }
    bool Object::getSolidity() {
        return m_isSolid;
    }

    void Object::setPosition(const Common::Vector2D<int>& pos) {
        m_position = pos;
    }
    Common::Vector2D<int> Object::getPosition() {
        return m_position;
    }

}