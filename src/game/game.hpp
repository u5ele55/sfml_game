#include <vector>
#include "../objects/object.hpp"
#include "../objects/creature.hpp"
#include <SFML/Graphics.hpp>

class GameCore {
public:
	int execute();
	void updateScene(const sf::Time&);
	void onEvent(const sf::Event&);
private:
	std::vector<Objects::Creature> m_creatures;
	std::vector<Objects::Object> m_objects;
	int m_playerIndex;
};
