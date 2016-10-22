#pragma once

#include "Vec2D.hpp"


namespace ei {
namespace common {

	struct CollisionPoint2D {
		CollisionPoint2D(Vec2D co_ordinates, bool exists);
		
		Vec2D co_ordinates;
		bool  exists;
	};

}	// namespace common
}	// namespace ei
