#pragma once

#include <Windows.h>
#include "CharColor.hpp"
#include "Attribute.hpp"


namespace ei {
namespace common {

	struct WChar {	// A wrapper class around CHAR_INFO
		
		WChar();
		WChar(wchar_t glyph, Attribute attribute);
		WChar(wchar_t glyph, CharColor fg, CharColor bg)
			: WChar(glyph, Attribute(fg, bg)) { }

		~WChar() { }

		inline wchar_t   &glyph() { return m_Glyph; }
		inline Attribute &attributes() { return m_Attribute; }

		CHAR_INFO export_windows_char_info();

	  protected:
		wchar_t		m_Glyph;
		Attribute   m_Attribute;
	};

}	// namespace common
}	// namespace ei
