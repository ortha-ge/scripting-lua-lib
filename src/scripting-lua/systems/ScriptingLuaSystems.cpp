module;

#include <utility>

#include <entt/entt.hpp>
#include <sol/sol.hpp>

module ScriptingLua.Systems;

import Core.EnTTRegistry;
import Core.Scheduler;

namespace ScriptingLua {

	constexpr char TestScriptLua[] = R"(
	local testVar = 1
	print(testVar)
)";

	ScriptingLuaSystems::ScriptingLuaSystems(Core::EnTTRegistry& registry, Core::Scheduler& scheduler)
		: mRegistry{ registry }
		, mScheduler{ scheduler } {

		sol::state luaState;
		luaState.open_libraries(sol::lib::base, sol::lib::package);
		luaState.script(TestScriptLua);

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
