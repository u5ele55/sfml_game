#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "../common/vector2d.hpp"
#include "../graphics/sprite_manager.hpp"

namespace Objects {
	class Object {
	public:
		explicit Object();
		explicit Object(const std::string &m_spriteName);
		Object(const std::string &m_spriteName, Common::Vector2D<double> position, bool isSolid = true);
		
		virtual void onInteraction(const Object &);
		virtual void onUpdate(const sf::Time &elapsedTime);
		virtual void onEvent(const sf::Event& event);

		void setSolidity(bool solid);
		bool getSolidity();

		Common::Vector2D<double>& position();

		Common::Vector2D<double>& velocity();

		sf::Sprite& sprite();
	protected:
		bool m_isSolid;
		Common::Vector2D<double> m_velocity;
		Common::Vector2D<double> m_position;
		std::string m_spriteName;
		sf::Sprite m_sprite;
	};
}

#endif