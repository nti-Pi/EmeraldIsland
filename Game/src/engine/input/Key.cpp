#include "Key.hpp"

#include <wchar.h>
#include <iostream>
#include "common/Logging.hpp"

using namespace ei::common;


namespace ei {
namespace engine {
namespace input {

	Key::Key(Symbol s)
		: m_Symbol(s) { }


	Key Key::get() {
		wchar_t wc = _getwch();
		if (wc == 0x0000 || wc == 0x00E0) {
			// We ignore the first character.
				
			wchar_t key_code = _getwch();

			switch (key_code) {
				// See KeyCodes image in docs:
				case 80:
					return Key::DOWN;
				case 72:
					return Key::UP;
				case 75:
					return Key::LEFT;
				case 77:
					return Key::RIGHT;
				case 54:
					return Key::RIGHT_SHIFT;
			}
		}

		switch (wc) {
			// Row 1:
			case L'`': return Key::BACK_QUOTE;				case L'~': return Key::TILDE;
			case L'1': return Key::_1;						case L'!': return Key::EXCLAMATION;
			case L'2': return Key::_2;						case L'@': return Key::AT_THE_RATE;
			case L'3': return Key::_3;						case L'#': return Key::HASH;
			case L'4': return Key::_4;						case L'$': return Key::DOLLAR;
			case L'5': return Key::_5;						case L'%': return Key::PERCENTAGE;
			case L'6': return Key::_6;						case L'^': return Key::CARET;
			case L'7': return Key::_7;						case L'&': return Key::AMPERSAND;
			case L'8': return Key::_8;						case L'*': return Key::ASTERISK;
			case L'9': return Key::_9;						case L'(': return Key::LEFT_BRACKET;
			case L'0': return Key::_0;						case L')': return Key::RIGHT_BRACKET;
			case L'-': return Key::MINUS;					case L'_': return Key::UNDERSCORE;
			case L'=': return Key::EQUALS;					case L'+': return Key::PLUS;

			// Row 2:
			case L'q': return Key::q;						case L'Q': return Key::Q;
			case L'w': return Key::w;						case L'W': return Key::W;
			case L'e': return Key::e;						case L'E': return Key::E;
			case L'r': return Key::r;						case L'R': return Key::R;
			case L't': return Key::t;						case L'T': return Key::T;
			case L'y': return Key::y;						case L'Y': return Key::Y;
			case L'u': return Key::u;						case L'U': return Key::U;
			case L'i': return Key::i;						case L'I': return Key::I;
			case L'o': return Key::o;						case L'O': return Key::O;
			case L'p': return Key::p;						case L'P': return Key::P;
			case L'[': return Key::LEFT_SQUARE_BRACKET;		case L'{': return Key::LEFT_CURLY_BRACKET;
			case L']': return Key::RIGHT_SQUARE_BRACKET;	case L'}': return Key::RIGHT_CURLY_BRACKET;
			case L'\\': return Key::BACK_SLASH;				case L'|': return Key::PIPE;

			// Row 3:
			case L'a': return Key::p0;						case L'A': return Key::A;
			case L's': return Key::s;						case L'S': return Key::S;
			case L'd': return Key::d;						case L'D': return Key::D;
			case L'f': return Key::f;						case L'F': return Key::F;
			case L'g': return Key::g;						case L'G': return Key::G;
			case L'h': return Key::h;						case L'H': return Key::H;
			case L'j': return Key::j;						case L'J': return Key::J;
			case L'k': return Key::k;						case L'K': return Key::K;
			case L'l': return Key::l;						case L'L': return Key::L;
			case L';': return Key::SEMICOLON;				case L':': return Key::COLON;
			case L'\'': return Key::QUOTE;					case L'"': return Key::DOUBLE_QUOTE;

			// Row 4:
			case L'z': return Key::z;						case L'Z': return Key::Z;
			case L'x': return Key::x;						case L'X': return Key::X;
			case L'c': return Key::c;						case L'C': return Key::C;
			case L'v': return Key::v;						case L'V': return Key::V;
			case L'b': return Key::p1;						case L'B': return Key::B;
			case L'n': return Key::n;						case L'N': return Key::N;
			case L'm': return Key::m;						case L'M': return Key::M;
			case L',': return Key::COMMA;					case L'<': return Key::LESS_THAN;
			case L'.': return Key::PERIOD;					case L'>': return Key::GREATER_THAN;
			case L'/': return Key::FORWARD_SLASH;			case L'?': return Key::QUESTION;

			// Row 5:
			case L' ': return Key::SPACE;
		}
	}


	void Key::decode(wchar_t c1, wchar_t c2) {
		if (c1 == 0 || c1 == 0xE0) {
			// Check c2 for key-codes!
			
		}
	}

}	// namespace input
}	// namespace engine
}	// namespace ei
