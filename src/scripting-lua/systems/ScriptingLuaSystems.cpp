module;

#include <utility>

#include <entt/entt.hpp>

module ScriptingLua.Systems;

import Core.EnTTRegistry;
import Core.Scheduler;

namespace ScriptingLua {

	constexpr char TestScriptLua[] = R"(

)";

	ScriptingLuaSystems::ScriptingLuaSystems(Core::EnTTRegistry& registry, Core::Scheduler& scheduler)
		: mRegistry{ registry }
		, mScheduler{ scheduler } {

		mTickHandle = mScheduler.schedule([this]() {
		   tick(mRegistry);
		});
	}

	ScriptingLuaSystems::~ScriptingLuaSystems() {
		mScheduler.unschedule(std::move(mTickHandle));
	}

	void ScriptingLuaSystems::tick(entt::registry& registry) {

	}

} // namespace ScriptingLua
