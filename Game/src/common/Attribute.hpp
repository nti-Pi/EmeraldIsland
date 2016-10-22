#pragma once

#include "CharColor.hpp"
#include <Windows.h>


namespace ei {
namespace common {

	struct Attribute {
		Attribute(CharColor fg_color = CharColor::WHITE, 
				  CharColor bg_color = CharColor::BLACK,
				  bool opaque = true)
			: m_ForegroundColor(fg_color), 
			  m_BackgroundColor(bg_color), 
			  m_Opaque(opaque) { }
	  
	  protected:
		CharColor m_ForegroundColor;
		CharColor m_BackgroundColor;
		bool  m_Opaque;

	  public:
		inline CharColor &foreground() { return m_ForegroundColor; }
		inline CharColor &background() { return m_BackgroundColor; }
		inline bool  &is_opaque() { return m_Opaque; }

		WORD export_windows_word();
	};

}	// namespace common
}	// namespace ei