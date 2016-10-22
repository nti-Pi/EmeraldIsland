#pragma once

#include "ConsoleManager.hpp"
#include "StateManager.hpp"
#include "InputManager.hpp"


namespace ei {
namespace engine {

	struct Engine {

		Engine();
		~Engine();

		void run(BaseState *init_state);
		void halt();

	  protected:
		bool			m_IsRunning;

		ConsoleManager	m_ConsoleManager;
		StateManager	m_StateManager;
		InputManager    m_InputManager;

		void init(BaseState *init_state);
		void de_init();

	  public:
		inline ConsoleManager &console_manager() { return m_ConsoleManager; }
		inline StateManager   &state_manager() { return m_StateManager; }
		inline InputManager   &input_manager() { return m_InputManager; }
	};

}	// namespace engine
}	// namespace ei
