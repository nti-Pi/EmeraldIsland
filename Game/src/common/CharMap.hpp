#pragma once

#include "WChar.hpp"
#include "geometry/Vec2u.hpp"
#include "geometry/Rect.hpp"
#include "Attribute.hpp"


namespace ei {
namespace common {

	struct CharMap {
		CharMap();
		CharMap(unsigned int width, unsigned int height);
		~CharMap();

		void init(unsigned int width, unsigned int height);
		void de_init();

		void fill(WChar c);
		void replace_all_glyphs(wchar_t old_glyph, wchar_t new_glyph);
		void replace_all_glyphs(wchar_t old_glyph, WChar new_charater);

		void write(Vec2i position, unsigned int text_len, const wchar_t *text, Attribute attributes);

		CHAR_INFO *export_native_windows_map();

	  protected:
		unsigned int	 m_NumColumns;
		unsigned int	 m_NumRows;
		WChar		    *m_CharBuffer;

	  public:
		inline unsigned int  width()									const { return m_NumColumns; }
		inline unsigned int  height()									const { return m_NumRows; }
		inline Vec2i		 dimensions()								const { return Vec2i(width(), height()); }
		inline Rect          rect()										const { return Rect(0, 0, width(), height()); }

		inline WChar        &char_at(const unsigned int x, const unsigned int y)		{ return m_CharBuffer[(y * width()) + x]; }
		inline WChar	    &char_at(const Vec2u &pos)									{ return char_at(pos.x, pos.y); }
		inline WChar         get_char(const unsigned int x, const unsigned int y) const { return m_CharBuffer[(y * width()) + x]; }
		inline WChar		 get_char(const Vec2u &pos)							  const { return get_char(pos.x, pos.y); }
		
	  public:
		static void blit(const CharMap &source, Rect source_rect, CharMap &destination, Rect dest_rect, bool copy_if_transparent = false);
		static void blit(const CharMap &source, CharMap &destination, Vec2i pos, bool copy_if_transparent = false);
	};

}	// namespace common
}	// namespace ei
