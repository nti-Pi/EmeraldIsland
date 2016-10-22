#include "Attribute.hpp"

#include <Windows.h>


namespace ei {
namespace common {

	WORD Attribute::export_windows_word() {
		WORD attributes = 0;
		if (foreground().get_red()) attributes = attributes | FOREGROUND_RED;
		if (foreground().get_green()) attributes = attributes | FOREGROUND_GREEN;
		if (foreground().get_blue()) attributes = attributes | FOREGROUND_BLUE;

		if (background().get_red()) attributes = attributes | BACKGROUND_RED;
		if (background().get_green()) attributes = attributes | BACKGROUND_GREEN;
		if (background().get_blue()) attributes = attributes | BACKGROUND_BLUE;

		if (foreground().get_is_intense()) attributes = attributes | FOREGROUND_INTENSITY;
		if (background().get_is_intense()) attributes = attributes | BACKGROUND_INTENSITY;

		return attributes;
	}

}	// namespace common
}	// namespace ei