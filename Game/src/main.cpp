#include <iostream>
#include "common/WChar.hpp"
#include <Windows.h>
#include "engine/Engine.hpp"

#include "game/WorldTest.hpp"
#include "common/Logging.hpp"

#include "common/ErrorControl.hpp"
#include "common/geometry/PolygonD.hpp"
#include "common/geometry/LineD.hpp"

using namespace std;
using namespace ei;
using namespace ei::common;
using namespace ei::engine;


int main(int argc, char *argv[]) {
	bool logging_init_success = Logging::init("C:/Users/Nikhil/Downloads/out_log.txt", 
											  "C:/Users/Nikhil/Downloads/error_log.txt");
	if (!logging_init_success)
		return -1;

	Logging::out() << "Testing Regular Output Log!" << endl;
	Logging::err() << "Testing Error Output Log!"	<< endl;

	Engine engine;
	game::WorldTest init_state = game::WorldTest(&engine);

	engine.run(&init_state);

	Logging::de_init();
	return 0;
}
