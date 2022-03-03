cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(Chry VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(GLFW_INCLUDE_NONE)
add_compile_definitions(SPDLOG_COMPILED_LIB)
add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=0)

if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++17")
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -ggdb3 -Wall -std=c++17")
endif()

set(core "${PROJECT_SOURCE_DIR}/Chry/Chry")
set(vendor "${PROJECT_SOURCE_DIR}/Chry/vendor")
set(sandbox "${PROJECT_SOURCE_DIR}/Sandbox")
set(deps "${PROJECT_SOURCE_DIR}/Chry/deps")

include_directories(${core})
include_directories(${sandbox})
include_directories(${vendor})
include_directories(${vendor}/glad/)
include_directories(${vendor}/glm/)
include_directories(${vendor}/spdlog/include)
include_directories(${vendor}/stb)

add_subdirectory(${vendor}/glad)
add_subdirectory(${vendor}/spdlog)
add_subdirectory(${vendor}/stb)

file(GLOB_RECURSE core_cpp "${core}/*.cpp")
file(GLOB_RECURSE sandbox_cpp "${sandbox}/*.cpp")

find_library(glfwlib libglfw.so PATHS "${deps}")
find_library(dllib libdl-2.33.so PATHS "${deps}")

add_library(Chry STATIC ${core_cpp})
target_link_libraries(Chry "glad")
target_link_libraries(Chry "spdlog")
target_link_libraries(Chry "stb")
target_link_libraries(Chry "${glfwlib}")
target_link_libraries(Chry "${dllib}")

add_executable(Sandbox ${sandbox_cpp})
target_link_libraries(Sandbox PRIVATE "Chry")
