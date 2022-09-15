#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "../common/vector2d.hpp"

namespace Objects {
	class Object {
	public:
		explicit Object();
		explicit Object(Common::Vector2D<int> position, bool isSolid = true);
		
		virtual void onInteraction(const Object &);

		void setSolidity(bool solid);
		bool getSolidity() const;

		void setPosition(const Common::Vector2D<int>&);
		Common::Vector2D<int> getPosition() const;
	protected:
		bool m_isSolid;
		Common::Vector2D<int> m_position;
	};
}

#endif