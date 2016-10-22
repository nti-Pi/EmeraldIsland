#pragma once

#include <wchar.h>
#include "BaseManager.hpp"
#include "input/Key.hpp"

using namespace ei::engine::input;


namespace ei {
namespace engine {

	struct InputManager : public BaseManager {

		InputManager(Engine *const parent_engine);

		void init();
		void de_init();

		Key poll_input();

	};

}	// namespace engine
}	// namespace ei
