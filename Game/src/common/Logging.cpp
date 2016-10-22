#include "Logging.hpp"
#include <iostream>
#include <fstream>

#include "ErrorControl.hpp"

using namespace std;


namespace ei {
namespace common {

	static bool		_IsInitialized = false;
	static ofstream _Out;
	static ofstream _Err;

	bool Logging::init(const char *out_file_name, const char *err_file_name) {
		_Out.open(out_file_name);
		_Err.open(err_file_name);

		if (!_Out.good()) {
			cerr << "Failed to open file out-stream '" << out_file_name << "'!" << endl;
			_IsInitialized = false;
			return false;
		}

		if (!_Err.good()) {
			cerr << "Failed to open file error-stream '" << err_file_name << "'!" << endl;
			_IsInitialized = false;
			return false;
		}

		_IsInitialized = true;
		return true;
	}


	void Logging::de_init() {
		_Out.close();
		_Err.close();
		_IsInitialized = false;
	}


	ofstream &Logging::out() {
		f_msg_assert(cerr, _IsInitialized, "Must initialize Logging module before using! Please look at Logging::init!");
		return _Out;
	}


	ofstream &Logging::err() {
		f_msg_assert(cerr, _IsInitialized, "Must initialize Logging module before using! Please look at Logging::init!");
		return _Err;
	}

}	// namespace common
}	// namespace ei