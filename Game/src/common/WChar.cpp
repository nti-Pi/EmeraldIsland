#include "WChar.hpp"

#include <wincon.h>


namespace ei {
namespace common {


	WChar::WChar() { }


	WChar::WChar(wchar_t glyph, Attribute attributes) 
		: m_Attribute(attributes),
		  m_Glyph(glyph) { }


	CHAR_INFO WChar::export_windows_char_info() {
		CHAR_INFO char_info;
		char_info.Char.UnicodeChar = m_Glyph;
		char_info.Attributes = m_Attribute.export_windows_word();
		return char_info;	
	}

}	// namespace common
}	// namespace ei
