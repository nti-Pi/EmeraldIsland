#pragma once

#include <wchar.h>
#include "common/CharMap.hpp"
#include "engine/input/Key.hpp"

using namespace ei::common;


namespace ei {
namespace engine {
	struct Engine;
	
namespace state {

	struct BaseState {

		BaseState(Engine *const parent_engine);

		virtual void on_activate() = 0;
		virtual void on_render(CharMap &render_target) = 0;
		virtual void on_update(input::Key input_char) = 0;
		virtual void on_de_activate() = 0;

	  protected:
		Engine *const m_ParentEngine;

	  public:
		inline Engine *const parent_engine() { return m_ParentEngine; }
	};

}	// namespace state
}	// namespace engine
}	// namespace ei
