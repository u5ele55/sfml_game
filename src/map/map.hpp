
#include <SFML/Graphics.hpp>
namespace Objects {
    namespace Map
    {
        class FieldMap  {
        public:
            void onUpdate(const sf::Time &elapsedTime);
            void onEvent(const sf::Event& event);
        };
    } // namespace Map
    
} // namespace Objects
