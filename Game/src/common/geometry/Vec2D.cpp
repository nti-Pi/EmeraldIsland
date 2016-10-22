#include "Vec2d.hpp"
#include <cmath>


namespace ei {
namespace common {

	Vec2D::Vec2D() 
		: x(0), y(0) { }

	Vec2D::Vec2D(double x_, double y_)
		: x(x_), y(y_) { }

	Vec2D::Vec2D(Vec2i vec2i)
		: Vec2D::Vec2D((double)vec2i.x, (double)vec2i.y) { }

	double Vec2D::length() const { return sqrt(x * x + y * y); }

	Vec2D operator + (const Vec2D p0, const Vec2D p1) { return Vec2D(p0.x + p1.x, p0.y + p1.y); }
	Vec2D operator - (const Vec2D p0, const Vec2D p1) { return p0 + (-p1); }
	Vec2D operator * (const Vec2D p0, const double lambda) { return Vec2D(p0.x * lambda, p0.y * lambda); }
	Vec2D operator / (const Vec2D p0, const double lambda) { return p0 * (1 / lambda); }

	double distance(const Vec2D v0, const Vec2D v1) { return (v1 - v0).length(); }
	double dot(const Vec2D a, const Vec2D b)		{ return a.x * b.x + a.y * b.y; }
	Vec2D  normalize(const Vec2D a)					{ return a / a.length(); }
	bool   parallel(const Vec2D a, const Vec2D b)	{
		if (b.x == 0)
			return a.x == 0;
		if (b.y == 0)
			return a.y == 0;

		return (a.x / b.x) == (a.y / b.y); 
	}

}	// namespace common
}	// namespace ei
