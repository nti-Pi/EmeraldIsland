#pragma once

#include <cstdio>
#include "Logging.hpp"

using namespace ei::common;


// Asserts a condition, and if it fails, prints a message to the specified stream and segfaults.
#define f_msg_assert(f, cond, msg) \
	((cond ? true : (f << "Failed Assertion: [" << msg << "]" << endl, *(char *)(nullptr) = '\0')))


// Does the same as fmsg_assert, but writes to the default Logging::err stream
#define msg_assert(cond, msg) (f_msg_assert(Logging::err(), cond, msg))