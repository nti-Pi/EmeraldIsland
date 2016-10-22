#include "Engine.hpp"

#include <iostream>
#include <conio.h>

#include "input/Key.hpp"


namespace ei {
namespace engine {

	Engine::Engine() 
		: m_IsRunning(false),
		  m_ConsoleManager(this),
		  m_StateManager(this),
		  m_InputManager(this) { }


	Engine::~Engine() { }


	void Engine::init(BaseState *init_state) {
		m_ConsoleManager.init();

		m_StateManager.init();
		m_StateManager.push_state(init_state);
		
		m_InputManager.init();

		m_IsRunning = true;
	}


	void Engine::de_init() {
		m_InputManager.de_init();
		m_StateManager.de_init();
		m_ConsoleManager.de_init();
	}


	void Engine::run(BaseState *init_state) {
		init(init_state);

		{	// Prompt:
			wchar_t prompt[100] = 
				L"Call of Booty! A game by Nikhil Idiculla, Rachit Malik, Pradhyumn Lath, and Archit Joshua.";
			m_ConsoleManager.render_target().write(Vec2i(0, 0), wcslen(prompt), prompt, Attribute());
			m_ConsoleManager.render();
			m_ConsoleManager.clear();
		}

		while (m_IsRunning) {
			
			Key input = m_InputManager.poll_input();

			m_StateManager.update(input);
			m_StateManager.render(m_ConsoleManager.render_target());

			m_ConsoleManager.render();
			m_ConsoleManager.clear();
		}

		de_init();
	}


	void Engine::halt() { m_IsRunning = false; }

}	// namespace engine
}	// namespace ei
