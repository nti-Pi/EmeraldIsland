#include "TestState.hpp"

#include <iostream>
#include "engine/Engine.hpp"
#include "common/WChar.hpp"
#include "common/geometry/Vec2i.hpp"

#include "MainMenu.hpp"

using namespace std;
using namespace ei::engine;
using namespace ei::engine::state;


namespace ei {
namespace game {

	void TestState::render_palette(int max_w, int max_h, CharMap &render_target) {
		int block_w = 16,
			block_h = 16;

		int ctr = 0;

		int w_factor = max_w / block_w;
		// Disregarding h_factor atm because of improper text-fills

		for (char r_fg = 0; r_fg <= 1; ++r_fg) {
			for (char g_fg = 0; g_fg <= 1; ++g_fg) {
				for (char b_fg = 0; b_fg <= 1; ++b_fg) {
					for (char r_bg = 0; r_bg <= 1; ++r_bg) {
						for (char g_bg = 0; g_bg <= 1; ++g_bg) {
							for (char b_bg = 0; b_bg <= 1; ++b_bg) {
								for (char fg_intense = 0; fg_intense <= 1; ++fg_intense) {
									for (char bg_intense = 0; bg_intense <= 1; ++bg_intense) {
										int y_set = ctr / block_w,
											x_set = w_factor * (ctr % block_w);

										Attribute attributes(CharColor((bool)r_fg, (bool)g_fg, (bool)b_fg, (bool)fg_intense),
																				 CharColor((bool)r_bg, (bool)g_bg, (bool)b_bg, (bool)bg_intense));

										render_target.write(Vec2i(x_set, y_set), w_factor, 
															L"Hello                      ", attributes);

										++ctr;
									}
								}
							}
						}
					}
				}
			}
		}
	}


	void TestState::render_message(CharMap &render_target) {
		wchar_t message[80];
		swprintf(message, sizeof(message), 
				 L"Use [%lc], [%lc], [%lc], and [%lc] to move! Hit [q] to quit! Hit [p] to change state!",
				 0x2191, 0x2193, 0x2190, 0x2192);	// Up, Down, Left, and Right

		render_target.write(
			m_MessagePos,
			wcslen(message),
			message,
			Attribute(CharColor(0, 0, 0, 0), CharColor(1, 1, 1, 1))
		);
	}
	

	void TestState::render_blu(CharMap &render_target) {
		CharMap::blit(m_MessageCharMap, render_target, m_MessagePos);
	}


	static
	void render_surf(CharMap &render_target) {
		render_target.fill(WChar('!', CharColor(true, false, false, false), CharColor(true, false, false, false)));
		
		CharMap box = CharMap(30, 30);
		box.fill(WChar('?', CharColor(true, true, false, true), CharColor(true, false, false, true)));
	}


	TestState::TestState(Engine *parent_engine) 
		: BaseState(parent_engine) { }


	void TestState::on_activate() {
		m_MessagePos = Vec2i(-1, -1);
		m_MessageCharMap = CharMap(3, 3);
	}


	void TestState::on_render(CharMap &render_target) {
		if (m_MessagePos.x == -1) {
			m_MessagePos = Vec2i(2, render_target.height() - 3);
		}

		render_surf(render_target);
		render_palette(render_target.width(), render_target.height(), render_target);
		render_message(render_target);
	}


	void TestState::on_update(Key input) {
		if (input == Key::UP)
			--m_MessagePos.y;
		else if (input == Key::DOWN)
			++m_MessagePos.y;
		else if (input == Key::LEFT)
			--m_MessagePos.x;
		else if (input == Key::RIGHT)
			++m_MessagePos.x;
		else if (input == Key::q)
			parent_engine()->halt();
		else if (input == Key::p)
			parent_engine()->state_manager().push_state(new MainMenu(parent_engine()));
	}

}	// namespace game
}	// namespace ei
