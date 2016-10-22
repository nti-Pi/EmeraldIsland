#pragma once

#include "Vec2D.hpp"
#include "LineD.hpp"


namespace ei {
namespace common {

	struct PolygonD {
		PolygonD(unsigned int num_points, Vec2D *points);
	
		friend bool collide_point(const PolygonD &p, const Vec2D &co_ordinates);

	  protected:
		unsigned int   m_NumLines;
		LineD		 **m_Lines;

	  public:
		inline const unsigned int  num_lines()			const { return m_NumLines;}
		inline const LineD		  &line(unsigned int i) const { return *(m_Lines[i]); }
	};

}	// namespace common
}	// namespace ei