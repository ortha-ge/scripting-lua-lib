 
cmake_minimum_required(VERSION 3.31)

find_package(sol2 CONFIG REQUIRED)
find_package(Lua CONFIG REQUIRED)

set (scripting-lua-lib-src
        src/scripting-lua/systems/ScriptingLuaSystems.cpp
)

set (scripting-lua-lib-modules
        src/scripting-lua/services/ScriptingLuaSystemsService.cppm
        src/scripting-lua/systems/ScriptingLuaSystems.cppm
)

add_library(scripting-lua-lib STATIC ${scripting-lua-lib-src} ${scripting-lua-lib-modules})

target_sources(scripting-lua-lib PUBLIC FILE_SET modules TYPE CXX_MODULES FILES ${scripting-lua-lib-modules})
target_compile_features(scripting-lua-lib PUBLIC cxx_std_23)
target_link_libraries(scripting-lua-lib PUBLIC core-lib sol2::sol2 ${LUA_LIBRARIES})
target_include_directories(scripting-lua-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

#add_subdirectory(tests)
