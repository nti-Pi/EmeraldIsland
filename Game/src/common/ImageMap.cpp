#include "ImageMap.hpp"
#include <fstream>

#include "geometry/LineD.hpp"
#include "Color3b.hpp"

using namespace std;


namespace ei {
namespace common {

	ImageMap::ImageMap()
		: m_Buffer(nullptr), m_Width(0), m_Height(0) { }

	ImageMap::ImageMap(unsigned int width, unsigned int height) {
		init(width, height);
	}


	void ImageMap::init(unsigned int width, unsigned int height) {
		// We try de-initializing the image-map:
		de_init();

		m_Buffer = new Color3b[width * height];
		m_Width = width;
		m_Height = height;
	}


	void ImageMap::de_init() {
		if (is_empty())
			return;

		delete[] m_Buffer;
		m_Buffer = nullptr;
		m_Width = m_Height = 0;
	}


	void ImageMap::export_ppm(const char *file_name) {
		ofstream f(file_name);
		if (!f.good())
			return;		// Failed to open file!
	}


	void ImageMap::fill(Color3b color) {
		for (unsigned int y = 0; y < m_Height; ++y)
			for (unsigned int x = 0; x < m_Width; ++x)
				pix_at(x, y) = color;
	}


	void ImageMap::draw_polygon(Color3b line_color, Color3b bg_color, PolygonD polygon) {
		for (unsigned int y = 0; y < m_Height; ++y) {
			for (unsigned int x = 0; x < m_Width; ++x) {
				// Checking if the point lies on the outline:
				for (unsigned int i = 0; i < polygon.num_lines(); ++i)
					if (collide_point(polygon.line(i), Vec2D(x, y))) {
						pix_at(x, y) = line_color;
						continue;
					}

				// Checking if the point is a fill:
				if (collide_point(polygon, Vec2D(x, y)))
					pix_at(x, y) = bg_color;
			}
		}
	}


}	// namespace common
}	// namespace ei
