#include "InputManager.hpp"


namespace ei {
namespace engine {

	InputManager::InputManager(Engine *const parent_engine)
		: BaseManager(parent_engine) { }


	void InputManager::init() { }

	void InputManager::de_init() { }


	Key InputManager::poll_input() {
		return Key::get();
	}

}	// namespace engine
}	// namespace ei
