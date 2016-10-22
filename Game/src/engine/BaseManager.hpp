#pragma once


namespace ei {
namespace engine {

	struct Engine;

	struct BaseManager {
		BaseManager(Engine *parent_engine);

	  protected:
		Engine *m_ParentEngine;

	  public:
		Engine *parent_engine() { return m_ParentEngine; }
	};

}	// namespace engine
}	// namespace ei
