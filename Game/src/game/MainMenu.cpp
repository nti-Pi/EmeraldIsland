#include "MainMenu.hpp"

#include "engine/Engine.hpp"
#include "engine/state/BaseState.hpp"

using namespace ei::engine;
using namespace ei::engine::state;


namespace ei {
namespace game {

	MainMenu::MainMenu(Engine *const parent_engine)
		: BaseState(parent_engine) { }


	void MainMenu::on_activate() {
		m_TitleMap = create_title_map();
	}


	void MainMenu::on_render(CharMap &render_target) {
		// Background:
		render_target.fill(WChar(L' ', CharColor(0, 0, 0, 0), CharColor(1, 0, 0, 0)));

		CharMap::blit(
			*m_TitleMap, 
			render_target, 
			Vec2i(
				(render_target.width() - m_TitleMap->width()) / 2,
				(render_target.height() - m_TitleMap->height()) / 2
			)
		);
	}

	void MainMenu::on_update(Key input_key) {
		if (input_key == Key::q)	
			parent_engine()->halt();
	}


	void MainMenu::on_de_activate() {
		m_TitleMap->de_init();
		delete m_TitleMap;
		m_TitleMap = nullptr;
	}


	CharMap *MainMenu::create_title_map() {
		const wchar_t SOLID_BLOCK = 0x25A0;		// Unicode code point of solid square
		const wchar_t S = SOLID_BLOCK;
		
		wchar_t line_1[] = L"$$$$$$$$ ###### #       #         $$$$$$$ #######   $$$$$$$ ####### ####### ####### #     #";
		wchar_t line_2[] = L"$        #    # #       #         $     $ #         $     $ #     # #     #    #    #     #";
		wchar_t line_3[] = L"$        ###### #       #         $     $ ######    $$$$$$  #     # #     #    #     ##### ";
		wchar_t line_4[] = L"$        #    # #       #         $     $ #         $     $ #     # #     #    #       #   ";
		wchar_t line_5[] = L"$$$$$$$$ #    # ####### #######   $$$$$$$ #         $$$$$$  ####### #######    #       #   ";

		CharMap *title = new CharMap((unsigned int)wcslen(line_1), 5);
		Attribute attributes(CharColor(0, 0, 0, 0), CharColor(0, 0, 0, 0), false);		// All transparent!

		title->write(Vec2i(0, 0), (unsigned int)wcslen(line_1), line_1, attributes);
		title->write(Vec2i(0, 1), (unsigned int)wcslen(line_2), line_2, attributes);
		title->write(Vec2i(0, 2), (unsigned int)wcslen(line_3), line_3, attributes);
		title->write(Vec2i(0, 3), (unsigned int)wcslen(line_4), line_4, attributes);
		title->write(Vec2i(0, 4), (unsigned int)wcslen(line_5), line_5, attributes);

		// Replacing ' ' with transparency:
		title->replace_all_glyphs(' ', WChar(' ', Attribute(
			CharColor(0, 0, 0, 0), CharColor(0, 0, 0, 0), false
		)));

		// Replacing the '#' with darker text, and '$' with brighter:
		title->replace_all_glyphs('#', WChar(' ', CharColor(0, 0, 0, 0), CharColor(1, 1, 1, 0)));
		title->replace_all_glyphs('$', WChar(' ', CharColor(0, 0, 0, 0), CharColor(1, 1, 1, 1)));

		return title;
	}

}	// namespace ei
}	// namespace game
