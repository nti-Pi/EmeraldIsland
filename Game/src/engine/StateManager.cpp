#include "StateManager.hpp"
#include <wchar.h>

#include "Engine.hpp"
#include "common/CharMap.hpp"
#include "common/ErrorControl.hpp"

using namespace std;


namespace ei {
namespace engine {

	StateManager::StateManager(Engine *parent_engine)
		: BaseManager(parent_engine) {

	}


	void StateManager::init() {

	}


	void StateManager::de_init() {

	}


	void StateManager::update(Key update_key) {
		
		// Update:
		m_Stack.top()->on_update(update_key);
	}



	void StateManager::render(CharMap &render_target) {
		m_Stack.top()->on_render(render_target);
	}


	void StateManager::push_state(BaseState *state) {
		if (!m_Stack.empty())
			m_Stack.top()->on_de_activate();

		m_Stack.push(state);
		m_Stack.top()->on_activate();
	}


	void StateManager::pop_state() {
		msg_assert(m_Stack.empty(), "Popped from empty StateManager!");

		m_Stack.pop();
	
		if (!m_Stack.empty())
			m_Stack.top()->on_activate();
	}

}	// namespace engine 
}	// namespace ei
