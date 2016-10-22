#pragma once

#include <fstream>

using namespace std;


namespace ei {
namespace common {

	namespace Logging {
	
		bool init(const char *out_file_name, const char *err_file_name);
		void de_init();

		ofstream &out();
		ofstream &err();
	
	}	// namespace Logging

}	// namespace common
}	// namespace ei
