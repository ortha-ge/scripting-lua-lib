module;

#include <entt/fwd.hpp>

export module ScriptingLua.Systems;

import Core.EnTTRegistry;
import Core.Scheduler;

export namespace ScriptingLua {

	class ScriptingLuaSystems {
	public:
		ScriptingLuaSystems(Core::EnTTRegistry&, Core::Scheduler&);
		~ScriptingLuaSystems();

		ScriptingLuaSystems(ScriptingLuaSystems&&) = delete;
		ScriptingLuaSystems& operator=(ScriptingLuaSystems&&) noexcept = delete;

		ScriptingLuaSystems(const ScriptingLuaSystems&) = delete;
		ScriptingLuaSystems& operator=(const ScriptingLuaSystems&) = delete;

		void tick(entt::registry&);

	private:
		Core::EnTTRegistry& mRegistry;
		Core::Scheduler& mScheduler;
		Core::TaskHandle mTickHandle{};
	};

} // namespace ScriptingLua
