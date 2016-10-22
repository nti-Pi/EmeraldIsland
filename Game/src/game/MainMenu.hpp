#pragma once

#include "engine/state/BaseState.hpp"

using namespace ei::engine;
using namespace ei::engine::state;
using namespace ei::engine::input;


namespace ei {
namespace game {

	struct MainMenu : public BaseState {
		MainMenu(Engine *const parent_engine);
	
		virtual void on_activate();
		virtual void on_render(CharMap &render_target);
		virtual void on_update(Key input_char);
		virtual void on_de_activate();

	  protected:
		CharMap *m_TitleMap;
		CharMap *create_title_map();
	};

}	// namespace ei
}	// namespace game
