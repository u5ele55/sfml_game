#ifndef MAP_GENERATOR_HPP
#define MAP_GENERATOR_HPP

#include "../map.hpp"

#include "rules/can_create_map.hpp"
#include "rules/field_size_rule.hpp"

namespace Map
{
    template <typename ... Rules>
    class MapGenerator {
    public:
        MapGenerator(MapGenerator&&) = delete;
        MapGenerator(const MapGenerator&) = delete;
        MapGenerator() = default;

        FieldMap generate() {
            (createField<Rules...>());
            (modifyField<Rules...>());
            return m_field;
        }

    private:
        FieldMap m_field;

        template <typename Rule, typename ... RestRules>
        void createField() {
            if constexpr (CanCreateMap<Rule>::value) {
                m_field = Rule::createMap();
            } 

            if constexpr (sizeof...(RestRules) > 0) {
                createField<RestRules...>();
            }
        }

        template <typename Rule, typename ... RestRules>
        void modifyField() {
            if constexpr (!CanCreateMap<Rule>::value) {
                Rule::changeMap(m_field);
            } 

            if constexpr (sizeof...(RestRules) > 0) {
                modifyField<RestRules...>();
            }
        }
    };
} // namespace Map


#endif