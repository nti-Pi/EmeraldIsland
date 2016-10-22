#pragma once

#include "Vec2i.hpp"


namespace ei {
namespace common {

	struct Rect {
		Rect(int x, int y, int w, int h);

		int x;
		int y;
		int w;
		int h;

		bool contains(int x, int y);	// Contains: checks if a point(Px, Py) : x <= Px <= w and y <= Py <= h
		bool contains(Vec2i co_ordinates);
	};

}	// namespace common
}	// namespace ei
