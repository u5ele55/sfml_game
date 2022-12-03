#include "test_event_creator.hpp"

#include <map>

#include "../../utilities/string_utilities.hpp"

#include "player_heal_event.hpp"
#include "damage_player_event.hpp"
#include "win_event.hpp"
#include "change_map_event.hpp"
#include "change_cell_event.hpp"
#include "player_speed_multiplier_event.hpp"

namespace Map
{

    TestEventCreator::TestEventCreator(FieldMap &field) : m_field(field) {}

    Events::Event* TestEventCreator::fromSlon(std::string slon) {
        std::map<std::string, std::string> mp = StringUtilities::slonToMap(slon);
        std::string name = mp["name"];
        Events::Event *event = nullptr;
        if (name == "PlayerHeal") 
            event = new Events::PlayerHealEvent(*m_field.player);
        
        if (name == "DamagePlayer") {
            int damage = stoi(mp["damage"]);
            event = new Events::DamagePlayerEvent(*m_field.player, damage);
        }
        if (name == "Win") {
            event = new Events::WinStateEvent(*m_field.state);
        }

        return event;
    }
} // namespace Map
