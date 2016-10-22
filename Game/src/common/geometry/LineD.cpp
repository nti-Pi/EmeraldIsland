#include "LineD.hpp"

#include <limits>

using namespace std;


namespace ei {
namespace common {

	LineD::LineD(const Vec2D point_a, const Vec2D point_b)
		: m_Point(point_a),
		  m_Direction(normalize(point_b - point_a)),
		  m_LambdaMax(distance(point_a, point_b)) { }


	bool collide_point(const LineD line, const Vec2D co_ordinates) {
		Vec2D intended_direction = line.p1() - line.p0();
		Vec2D actual_direction = co_ordinates - line.p0();

		if (parallel(actual_direction, intended_direction)) {
			// Solving for lambda:
			// p0 + lambda * direction = p1
			// (p1 - p0) = lambda * direction
			// p1 - p0 and direction are in proportion of lambda!
			
			double lambda;
			if (line.m_Direction.x != 0)
				lambda = actual_direction.x / line.m_Direction.x;
			else if (line.m_Direction.y != 0)
				lambda = actual_direction.y / line.m_Direction.y;
			else
				return actual_direction.x == line.m_Direction.x &&
					   actual_direction.y == line.m_Direction.y;

			if (0.0 <= lambda && lambda <= line.m_LambdaMax)
				return true;
		}

		return false;
	}


	CollisionPoint2D collide_line(const LineD line_a, const LineD line_b) {
		// Lines are parallel! No definite solution exists!
		if (parallel(line_a.m_Direction, line_b.m_Direction))
			return CollisionPoint2D(Vec2D(0, 0), false);

		// Solving for X:
		double x;
		if (line_b.slope() == numeric_limits<double>::infinity() || line_b.slope() == -numeric_limits<double>::infinity())
			x = line_b.m_Point.x;
		else if (line_a.slope() == numeric_limits<double>::infinity() || line_a.slope() == -numeric_limits<double>::infinity())
			x = line_a.m_Point.x;
		else
			x = (line_a.y_intercept() - line_b.y_intercept()) / (line_b.slope() - line_a.slope());

		// Solving for Y:
		double y;
		if (line_a.slope() == numeric_limits<double>::infinity())
			y = line_b.slope() * x + line_b.y_intercept();
		else
			y = line_a.slope() * x + line_a.y_intercept();

		bool is_solution = collide_point(line_a, Vec2D(x, y)) && collide_point(line_b, Vec2D(x, y));
		return CollisionPoint2D(Vec2D(x, y), is_solution);
	}

}	// namespace common
}	// namespace ei
