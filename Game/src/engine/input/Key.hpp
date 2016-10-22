#pragma once


namespace ei {
namespace engine {
namespace input {

	struct Key {

		enum Symbol {
			ESCAPE,
			BACK_QUOTE, TILDE,
			_1, EXCLAMATION,
			_2, AT_THE_RATE,
			_3, HASH,
			_4, DOLLAR,
			_5, PERCENTAGE,
			_6, CARET,
			_7, AMPERSAND,
			_8, ASTERISK,
			_9, LEFT_BRACKET,
			_0, RIGHT_BRACKET,
			MINUS, UNDERSCORE,
			EQUALS, PLUS,
			BACKSPACE,
			TAB,
			Q, q,
			W, w,
			E, e,
			R, r,
			T, t,
			Y, y,
			U, u,
			I, i,
			O, o,
			P, p,
			LEFT_SQUARE_BRACKET, LEFT_CURLY_BRACKET,
			RIGHT_SQUARE_BRACKET, RIGHT_CURLY_BRACKET,
			BACK_SLASH,
			PIPE,
			A, p0,
			S, s,
			D, d,
			F, f,
			G, g,
			H, h,
			J, j,
			K, k,
			L, l,
			SEMICOLON, COLON,
			QUOTE, DOUBLE_QUOTE,
			ENTER,
			LEFT_SHIFT,
			Z, z,
			X, x,
			C, c,
			V, v,
			B, p1,
			N, n,
			M, m,
			COMMA, LESS_THAN,
			PERIOD, GREATER_THAN,
			FORWARD_SLASH, QUESTION,
			RIGHT_SHIFT,

			SPACE,
			LEFT,
			RIGHT,
			UP,
			DOWN
		};

		Key(Symbol symbol);
		static Key get();

		void decode(wchar_t c1, wchar_t c2);

		friend bool operator == (Key k, Symbol s) { return k.m_Symbol == s; }
		friend bool operator == (Symbol s, Key k) { return k == s; }

	  protected:
		Symbol m_Symbol;
	};

}	// namespace input
}	// namespace engine
}	// namespace ei
