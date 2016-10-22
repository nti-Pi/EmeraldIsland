#pragma once

#include <cstdint>


namespace ei {
namespace common {

	struct CharColor {

		enum ComponentMask {
			RED = 1,
			GREEN = 2,
			BLUE = 4,
			IS_INTENSE = 8
		};

		CharColor(bool red, bool green, bool blue, bool is_intense);
		CharColor(int red, int green, int blue, int is_intense);
		~CharColor() { }

	  protected:
		uint8_t m_ColorField;

		void set_mask(bool value, ComponentMask mask) {
			if (value)
				m_ColorField |= mask;
			else
				m_ColorField &= ~mask;
		}
	
	  public:

		inline bool get_red()		 { return (bool)(m_ColorField & ComponentMask::RED); }
		inline bool get_green()		 { return (bool)(m_ColorField & ComponentMask::GREEN); }
		inline bool get_blue()		 { return (bool)(m_ColorField & ComponentMask::BLUE); }
		inline bool get_is_intense() { return (bool)(m_ColorField & ComponentMask::IS_INTENSE); }
		
		inline void set_red(bool value = true) { set_mask(value, ComponentMask::RED); }
		inline void set_green(bool value = true) { set_mask(value, ComponentMask::GREEN); }
		inline void set_blue(bool value = true) { set_mask(value, ComponentMask::BLUE); }
		inline void set_is_intense(bool value = true) { set_mask(value, ComponentMask::IS_INTENSE); }
		
		static const CharColor WHITE;
		static const CharColor GRAY;
		static const CharColor BLACK;
		static const CharColor BRIGHT_RED;
		static const CharColor BRIGHT_GREEN;
		static const CharColor BRIGHT_BLUE;
		static const CharColor DARK_RED;
		static const CharColor DARK_GREEN;
		static const CharColor DARK_BLUE;
	};

}	// namespace common
}	// namespace ei
