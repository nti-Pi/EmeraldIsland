#pragma once


namespace ei {
namespace common {

	struct Color3b {
		Color3b();
		Color3b(unsigned char r_, unsigned char g_, unsigned char b_);

		unsigned char r;
		unsigned char g;
		unsigned char p1;
	};

}	// namespace common
}	// namespace ei