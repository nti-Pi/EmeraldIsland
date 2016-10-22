#include "CollisionPoint2D.hpp"


namespace ei {
namespace common {

	CollisionPoint2D::CollisionPoint2D(Vec2D point_, bool exists_)
		: co_ordinates(point_), exists(exists_) { }

}	// namespace common
}	// namespace ei
