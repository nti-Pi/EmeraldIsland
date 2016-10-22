#pragma once

#include "Color3b.hpp"
#include "geometry/Vec2i.hpp"
#include "geometry/PolygonD.hpp"


namespace ei {
namespace common {

	struct ImageMap {

		ImageMap();
		ImageMap(unsigned int width, unsigned int height);

		void init(unsigned int width, unsigned int height);
		void de_init();

		void export_ppm(const char *file_path);
		void fill(Color3b fill_color);
		void draw_polygon(Color3b line_color, Color3b bg_color, PolygonD polygon);

	  protected:
		unsigned int  m_Width;
		unsigned int  m_Height;
		Color3b      *m_Buffer;

	  public:
		inline bool			 is_empty() { return m_Buffer == nullptr; }
		inline Color3b		&pix_at(unsigned int x, unsigned int y) { return m_Buffer[y * m_Width + x]; }
		inline unsigned int  width() { return m_Width; }
		inline unsigned int  height() { return m_Height; }
	};

}	// namespace common
}	// namespace ei
