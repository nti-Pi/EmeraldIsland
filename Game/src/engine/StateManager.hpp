#pragma once

#include <stack>

#include "BaseManager.hpp"
#include "common/CharMap.hpp"
#include "input/Key.hpp"
#include "state/BaseState.hpp"


using namespace std;
using namespace ei::common;
using namespace ei::engine::input;
using namespace ei::engine::state;


namespace ei {
namespace engine {

	struct StateManager : public BaseManager {

		StateManager(Engine *parent_engine);

		void init();
		void de_init();

		void update(Key input_key);
		void render(CharMap &render_target);

		void push_state(state::BaseState *state);
		void pop_state();

	  protected:
		  stack<BaseState *> m_Stack;
	};

}	// namespace engin
}	// namespace ei
