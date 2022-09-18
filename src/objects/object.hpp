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
	};
}

#endif