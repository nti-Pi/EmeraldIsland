#pragma once

#include <Windows.h>
#include "BaseManager.hpp"
#include "common/CharMap.hpp"

using namespace ei::common;


namespace ei {
namespace engine {

	struct ConsoleManager : public BaseManager {

		ConsoleManager(Engine *parent_engine);
		~ConsoleManager();

		void init();
		void de_init();

		void render();
		void clear();

	  protected:
		HANDLE	m_WinCSBHandle;		// Windows Console Screen Buffer Handle
		CharMap m_TargetSurface;

	  public:
		inline unsigned int  num_columns() { return m_TargetSurface.width(); }
		inline unsigned int  num_rows()	  { return m_TargetSurface.height(); }

		inline CharMap      &render_target() { return m_TargetSurface; }
	};

}	// namespace engine
}	// namespace ei
