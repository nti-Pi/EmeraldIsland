#pragma once

#include "Vec2D.hpp"
#include "CollisionPoint2D.hpp"


namespace ei {
namespace common {

	struct LineD {
		LineD(const Vec2D point_a, const Vec2D point_b);

		friend bool				collide_point(const LineD line, const Vec2D co_ordinates);
		friend CollisionPoint2D collide_line(const LineD line_a, const LineD line_b);

	  protected:
		const Vec2D  m_Point;
		const Vec2D  m_Direction;
		const double m_LambdaMax;
	
	  public:
		inline const Vec2D &p0()				const { return m_Point; }
		inline const Vec2D &p1()				const { return m_Point + (m_LambdaMax * m_Direction); }

		inline const double slope()				const { return m_Direction.y / m_Direction.x; }

		inline const double y_intercept()		const { return m_Point.y - slope() * m_Point.x; }
	};

}	// namespace common
}	// namespace ei
