#pragma once

#include "Tile.hpp"
#include <vector>
#include "common/geometry/Vec2d.hpp"

using namespace std;
using namespace ei::common;


namespace ei {
namespace game {
namespace world_test {

	struct Map {
		Map(unsigned int width, unsigned int height);

		void generate();

	  protected:
		struct _Triangle {
			unsigned int i_a;
			unsigned int i_b;
			unsigned int i_c;
		};

		unsigned int		m_Width;
		unsigned int		m_Height;

		Tile		*const	m_TileMap;

		void				_initialize_map();
		vector<Vec2D>		_generate_points(unsigned int avg_point_distance);
		vector<_Triangle>	_generate_triangles(vector<Vec2D> points);

	  public:
		Tile &tile_at(unsigned int x, unsigned int y) { return m_TileMap[y * m_Width + x]; }
	};

}	// namespace world_test
}	// namespace game
}	// namespace ei