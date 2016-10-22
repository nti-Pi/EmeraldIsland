#include "Rect.hpp"


namespace ei {
namespace common {

	Rect::Rect(int x_, int y_, int w_, int h_)
		: x(x_), y(y_), w(w_), h(h_) { }


	bool Rect::contains(Vec2i co_ordinates) {
		return contains(co_ordinates.x, co_ordinates.y);
	}


	bool Rect::contains(int x_, int y_) {
		return x <= x_ && x_ <= w && y <= y_ && y_ <= h;
	}

}	// namespace common
}	// namespace ei
