#pragma once 

#include "engine/state/BaseState.hpp"
#include <wchar.h>

using namespace ei::engine;
using namespace ei::engine::state;
using namespace ei::engine::input;


namespace ei {
namespace game {

	struct TestState : public BaseState {

		TestState(Engine *const parent_engine);

		virtual void on_activate();
		virtual void on_render(CharMap &render_target);
		virtual void on_update(Key input_char);
		virtual void on_de_activate() { };

	  protected:
		Vec2i   m_MessagePos;
		CharMap m_MessageCharMap;

		void render_message(CharMap &render_target);
		void render_palette(int max_w, int max_h, CharMap &render_target);
		void render_blu(CharMap &render_target);
	};

}	// namespace game
}	// namespace ei
