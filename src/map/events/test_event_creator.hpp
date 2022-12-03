#ifndef TEST_EVENT_CREATOR
#define TEST_EVENT_CREATOR

#include "event_creator.hpp"
#include "../map.hpp"

namespace Map
{
    class TestEventCreator : public EventCreator {
    public:
        TestEventCreator(FieldMap& field);
        Events::Event* fromSlon(std::string slon);
    private:
        FieldMap &m_field;
    };
} // namespace Map


#endif