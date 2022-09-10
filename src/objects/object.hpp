#include <SFML/Graphics.hpp>
#include "../common/vector2d.hpp"
#include "../graphics/texture_manager.hpp"

class Object {
public:
	explicit Object();
	explicit Object(const Graphics::TextureType &textureType);
	Object(const Graphics::TextureType &textureType, Common::Vector2D<double> position, bool isSolid = true);
	
	virtual void onInteraction(const Object &);
	virtual void onUpdate(const sf::Time &elapsedTime);

	void setSolidity(bool solid);
	bool getSolidity();

	Common::Vector2D<double>& position();

	Common::Vector2D<double>& velocity();

	sf::Sprite& sprite();
protected:
	bool m_isSolid;
	Common::Vector2D<double> m_velocity;
	Common::Vector2D<double> m_position;
	sf::Sprite m_sprite;
};
