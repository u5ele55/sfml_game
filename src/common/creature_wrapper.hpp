#ifndef CREATURE_WRAPPER_HPP
#define CREATURE_WRAPPER_HPP

#include "vector2d.hpp"
#include "../objects/creature.hpp"

namespace Common
{
    struct CreatureWrapper {
        Vector2D<int> position;
        Objects::Creature creature;

        CreatureWrapper(const Vector2D<int> &pos, const Objects::Creature &cr) : position(pos), creature(cr) {}
    };
} // namespace Common

#endif