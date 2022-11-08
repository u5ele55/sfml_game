#ifndef FIELD_SIZE_RULE_HPP
#define FIELD_SIZE_RULE_HPP

#include "../../map.hpp"

namespace Map
{

    template <int x, int y>
    class FieldSizeRule {
    public:
        static FieldMap createMap() {
            return FieldMap(x, y);
        }
    };
} // namespace Map


#endif