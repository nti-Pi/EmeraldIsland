#include "WorldTest.hpp"

#include <iostream>
#include <wchar.h>
#include "engine/Engine.hpp"
#include "common/Logging.hpp"

using namespace std;
using namespace ei::engine;
using namespace ei::engine::state;


namespace ei {
namespace game {

	WorldTest::WorldTest(Engine *parent_engine)
		: BaseState(parent_engine),
		  m_Map(1024, 1024) { }


	void WorldTest::on_activate() {
		m_Map.generate();
	}


	void WorldTest::on_render(CharMap &render_target) {
		wchar_t line_1[] = L"Map Test";
		wchar_t line_2[] = L"Hit [q] to quit.";
		render_target.write(Vec2i(0, 0), wcslen(line_1), line_1, Attribute());
		render_target.write(Vec2i(0, 1), wcslen(line_2), line_2, Attribute());
	}


	void WorldTest::on_update(Key input) {
		if (input == Key::q)
			parent_engine()->halt();
	}

}	// namespace game
}	// namespace ei
