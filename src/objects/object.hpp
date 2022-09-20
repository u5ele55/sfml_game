#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "../common/vector2d.hpp"

namespace Objects {
	class Object {
	public:
		explicit Object();
		
		virtual void onInteraction(const Object &);
	};
}

#endif