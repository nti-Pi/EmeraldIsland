#include "PolygonD.hpp"
#include <limits>

using namespace std;


namespace ei {
namespace common {

	/// <summary>
	/// Creates a polygon from points provided in CONUTER-CLOCKWISE WINDING ORDER.
	/// </summary>
	PolygonD::PolygonD(unsigned int num_points, Vec2D *points) {
		m_NumLines = num_points;
		m_Lines = new LineD *[m_NumLines];

		for (unsigned int i = 0; i < num_points; ++i)
			m_Lines[i] = new LineD(points[i], points[(i + 1) % num_points]);
	}


	bool collide_point(const PolygonD &p, const Vec2D &co_ordinates) {
		// We use the Even-Odd rule to determine whether (x, y) lies in the polygon.
		// https://en.wikipedia.org/wiki/Even%E2%80%93odd_rule
		// We consider a projected ray (just a line parrallel to the X-axis passing through the point), 
		// solve all the collision points with the polygon's edges, and only select those with an X-component 
		// less than that of the point under consideration in order to find the intersection count.

		LineD projected_ray = LineD(Vec2D(-pow(2, 15), co_ordinates.y), co_ordinates);

		if (co_ordinates.x == 100.0 && co_ordinates.y == 10.0)
		{
			int temp = 24;
		}

		unsigned int num_ray_collisions = 0;
		for (unsigned int i_line = 0; i_line < p.num_lines(); ++i_line) {
			CollisionPoint2D collision_point = collide_line(projected_ray, p.line(i_line));

			if (collision_point.exists)
				if (collision_point.co_ordinates.x <= (double)co_ordinates.x)
					++num_ray_collisions;
		}


		return (num_ray_collisions % 2);
	}

}	// namespace common
}	// namespace ei
