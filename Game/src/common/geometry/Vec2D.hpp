#pragma once

#include "Vec2i.hpp"


namespace ei {
namespace common {

	struct Vec2D {
		double x;
		double y;

		Vec2D();
		Vec2D(double x, double y);
		Vec2D(Vec2i v2i);

		double length() const;

		friend Vec2D operator + (const Vec2D p0, const Vec2D p1);
		friend Vec2D operator - (const Vec2D p0, const Vec2D p1);
		friend Vec2D operator * (const Vec2D p0, const double lambda);
		friend Vec2D operator / (const Vec2D p0, const double lambda);
		inline friend Vec2D operator - (const Vec2D p0)				{ return -1 * p0; }
		inline friend Vec2D operator * (const double lambda, const Vec2D p0) { return p0 * lambda; }
		inline friend Vec2D operator / (const double lambda, const Vec2D p0) { return p0 / lambda; }

		friend double dot(const Vec2D a, const Vec2D b);
		friend Vec2D  normalize(const Vec2D v);
		friend double distance(const Vec2D v0, const Vec2D v1);
		friend bool   parallel(const Vec2D a, const Vec2D b);

	};

}	// nmaespace common
}	// namespace ei
