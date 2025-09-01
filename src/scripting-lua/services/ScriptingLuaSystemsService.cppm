
export module ScriptingLua.SystemsService;

import kangaru;
import Core.EnTTRegistryService;
import Core.SchedulerService;
export import ScriptingLua.Systems;

export namespace ScriptingLua {

	class ScriptingLuaSystemsService : public kgr::single_service<ScriptingLuaSystems, kgr::dependency<Core::EnTTRegistryService, Core::SchedulerService>>{};

} // ScriptingLua
