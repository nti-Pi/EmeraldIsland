#include "CharColor.hpp"


namespace ei {
namespace common {

	const CharColor CharColor::WHITE = CharColor(1, 1, 1, 1);
	const CharColor CharColor::GRAY = CharColor(1, 1, 1, 0);
	const CharColor CharColor::BLACK = CharColor(0, 0, 0, 0);
	const CharColor CharColor::BRIGHT_RED = CharColor(1, 0, 0, 1);
	const CharColor CharColor::BRIGHT_GREEN = CharColor(0, 1, 0, 1);
	const CharColor CharColor::BRIGHT_BLUE = CharColor(0, 0, 1, 1);
	const CharColor CharColor::DARK_RED = CharColor(1, 0, 0, 0);
	const CharColor CharColor::DARK_GREEN = CharColor(0, 1, 0, 0);
	const CharColor CharColor::DARK_BLUE = CharColor(0, 0, 1, 0);


	CharColor::CharColor(bool red, bool green, bool blue, bool is_intense) {
		set_red(red);
		set_green(green);
		set_blue(blue);
		set_is_intense(is_intense);
	}


	CharColor::CharColor(int red, int green, int blue, int is_intense)
		: CharColor::CharColor((bool)red, (bool)green, (bool)blue, (bool)is_intense) { }

}	// namespace common
}	// namespace twiw
