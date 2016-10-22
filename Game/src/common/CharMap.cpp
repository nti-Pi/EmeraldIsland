#include "CharMap.hpp"

#include <iostream>
#include <algorithm>

using namespace std;


namespace ei {
namespace common {

	CharMap::CharMap()
		: m_CharBuffer(nullptr),
		  m_NumColumns(0), m_NumRows(0) { }

	CharMap::CharMap(unsigned int width, unsigned int height)
		: CharMap() {
		init(width, height);
	}

	CharMap::~CharMap() {
		// de_init();
		// MUST MANUALLY DE-ALLOCATE!
	}


	void CharMap::init(unsigned int width, unsigned int height) {
		de_init();	// We try de-initializing any existing surface / memory

		m_NumColumns = width;
		m_NumRows = height;
		m_CharBuffer = new WChar[width * height];
	}


	void CharMap::de_init() {
		if (m_CharBuffer == nullptr)
			return;		// Already de-initialized!

		// FIXME: Mem leak, only commented out for debug:
		delete[] m_CharBuffer;
		m_CharBuffer = nullptr;
		m_NumColumns = 0;
		m_NumRows = 0;
	}


	void CharMap::fill(WChar c) {
		for (unsigned int y = 0; y < height(); ++y)
			for (unsigned int x = 0; x < width(); ++x)
				char_at(x, y) = c;
	}


	void CharMap::replace_all_glyphs(wchar_t old_glyph, wchar_t new_glyph) {
		for (unsigned int y = 0; y < height(); ++y)
			for (unsigned int x = 0; x < width(); ++x)
				if (char_at(x, y).glyph() == old_glyph)
					char_at(x, y).glyph() = (new_glyph);
	}


	void CharMap::replace_all_glyphs(wchar_t old_glyph, WChar new_character) {
		for (unsigned int y = 0; y < height(); ++y)
			for (unsigned int x = 0; x < width(); ++x)
				if (char_at(x, y).glyph() == old_glyph)
					char_at(x, y) = new_character;
	}


	void CharMap::blit(const CharMap &source, Rect source_rect, CharMap &destination, Rect dest_rect, bool copy_if_transparent) {
		// Writing the simplest thing that will work (though inefficient)

		for (int y_src = source_rect.y; y_src < source_rect.h + source_rect.y; ++y_src) {
			for (int x_src = source_rect.x; x_src < source_rect.w + source_rect.x; ++x_src) {
				if (!source.rect().contains(x_src, y_src))
					continue;	// We skip this invalid source-character.

				if (!copy_if_transparent && !source.get_char(x_src, y_src).attributes().is_opaque())
					continue;		// The source is transparent for this character!

				int y_dst = dest_rect.y + (y_src - source_rect.y),
					x_dst = dest_rect.x + (x_src - source_rect.x);

				if (!destination.rect().contains(x_dst, y_dst))
					continue;	// We skip this invalid destination-character!.

				destination.char_at(x_dst, y_dst) = source.get_char(x_src, y_src);
			}
		}
	}


	// Convenience overloads of blit:
	void CharMap::blit(const CharMap &source, CharMap &destination, Vec2i pos, bool copy_if_transparent) {
		CharMap::blit(source, source.rect(), destination, Rect(pos.x, pos.y, 
															   pos.x + source.width(), pos.y + source.height()), 
					  copy_if_transparent);
	}


	void CharMap::write(Vec2i position, unsigned int text_len, const wchar_t *text, Attribute attributes) {
		for (unsigned int i_text = 0; i_text < text_len; ++i_text) {
			int x_draw = position.x + i_text,
				y_draw = position.y;

			if (rect().contains(x_draw, y_draw)) {
				char_at(x_draw, y_draw) = WChar(text[i_text], attributes);
			}
		}
	}


	CHAR_INFO *CharMap::export_native_windows_map() {
		CHAR_INFO *map = new CHAR_INFO[width() * height()];
		
		for (unsigned int y = 0; y < height(); ++y)
			for (unsigned int x = 0; x < width(); ++x)
				map[y * width() + x] = char_at(x, y).export_windows_char_info();
		
		return map;
	}


}	// namespace common
}	// namespace ei
