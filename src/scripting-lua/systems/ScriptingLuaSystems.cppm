module;

export module ScriptingLua.Systems;

import Core.Scheduler;
import entt;

export namespace ScriptingLua {

	class ScriptingLuaSystems {
	public:
		ScriptingLuaSystems(entt::registry&, Core::Scheduler&);
		~ScriptingLuaSystems();

		ScriptingLuaSystems(ScriptingLuaSystems&&) = delete;
		ScriptingLuaSystems& operator=(ScriptingLuaSystems&&) noexcept = delete;

		ScriptingLuaSystems(const ScriptingLuaSystems&) = delete;
		ScriptingLuaSystems& operator=(const ScriptingLuaSystems&) = delete;

		void tick(entt::registry&);

	private:
		entt::registry& mRegistry;
		Core::Scheduler& mScheduler;
		Core::TaskHandle mTickHandle{};
	};

} // namespace ScriptingLua
