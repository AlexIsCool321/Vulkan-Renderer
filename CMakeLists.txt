cmake_minimum_required(VERSION 3.10)
project("Vulkan_Renderer")

set (CMAKE_C_STANDARD 99)
set (CMAKE_C_STANDARD_REQUIRED ON)
set (CMAKE_C_EXTENSIONS OFF)

find_package (glfw3 REQUIRED)
find_package (Vulkan REQUIRED)

file (GLOB_RECURSE SOURCES "src/*.c")

add_executable (${PROJECT_NAME} ${SOURCES})

target_include_directories (${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")
target_link_libraries (${PROJECT_NAME} PRIVATE m glfw Vulkan::Vulkan)

set_target_properties (${PROJECT_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY	"${CMAKE_SOURCE_DIR}/OUT"
)