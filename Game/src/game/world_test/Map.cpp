#include "Map.hpp"

#include <chrono>
#include <random>
#include <algorithm>

#include "Tile.hpp"
#include "common/Logging.hpp"

using namespace std;
using namespace std::chrono;


namespace ei {
namespace game {
namespace world_test {

	void Map::_initialize_map() {
		for (unsigned int y = 0; y < m_Height; ++y)
			for (unsigned int x = 0; x < m_Width; ++x)
				tile_at(x, y).init();
	}


	vector<Vec2D> Map::_generate_points(unsigned int avg_point_distance) {
		vector<Vec2D> points;

		// Let us assume a uniform point distribution along the intersections of grid cells in the map.
		// In such a manner, the width of each grid cell is a,
		// and avg_point_distance = root(2) * a
		// Number of points is width / a * height / a = width * height / a^2 = width * height * 2 / avg_point_distance^2
		unsigned int num_points = (m_Width * m_Height * 2) / (avg_point_distance * avg_point_distance);
		
		unsigned int seed = chrono::high_resolution_clock::now().time_since_epoch().count();
		default_random_engine generator(seed);
		uniform_real_distribution<> x_dist(0.0, (double)m_Width);
		uniform_real_distribution<> y_dist(0.0, (double)m_Height);

		for (unsigned int i_point = 0; i_point < num_points; ++i_point)
			points.push_back(Vec2D(x_dist(generator), y_dist(generator)));

		return points;
	}


	vector<Map::_Triangle> Map::_generate_triangles(vector<Vec2D> points) {
		// Sorting points in increasing order of x, y:
		sort(points.begin(), points.end(), [](auto a, auto b) { return a.y < b.y; });
		stable_sort(points.begin(), points.end(), [](auto a, auto b) { return a.x < b.x; });

		for (auto it = points.begin(); it != points.end(); ++it)
			Logging::out() << it->x << ' ' << it->y << endl;
		return vector<Map::_Triangle>();
	}


	Map::Map(unsigned int width, unsigned int height)
		: m_Width(width), m_Height(height), 
		  m_TileMap(new Tile[width * height]) { }


	void Map::generate() {
		_initialize_map();
		_generate_triangles(_generate_points(200));
	}

}	// namespace world_test
}	// namespace game
}	// namespace ei
