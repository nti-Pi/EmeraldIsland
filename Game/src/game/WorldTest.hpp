#pragma once 

#include "engine/state/BaseState.hpp"
#include <wchar.h>

#include "world_test/Map.hpp"

using namespace ei::engine;
using namespace ei::engine::state;
using namespace ei::engine::input;

using namespace ei::game::world_test;


namespace ei {
namespace game {

	struct WorldTest : public BaseState {

		WorldTest(Engine *const parent_engine);

		virtual void on_activate();
		virtual void on_render(CharMap &render_target);
		virtual void on_update(Key input_char);
		virtual void on_de_activate() { };

	  protected:
		Map m_Map;
	};

}	// namespace game
}	// namespace ei
