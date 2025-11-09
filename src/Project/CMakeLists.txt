cmake_minimum_required(VERSION 3.10)
project(Project)

# Packages
find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)


# Third Party
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${Vulkan_INCLUDE_DIRS})


# Sources
file(GLOB_RECURSE SOURCE "*.cpp" "*.h")


# Executable
add_executable(${PROJECT_NAME} ${SOURCE})


# Libraries Inlcude Directories
target_link_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/Out/Bin")


# Dependencies
add_dependencies(${PROJECT_NAME} "Renderer")


# Libraries
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)
target_link_libraries(${PROJECT_NAME} "Renderer")


# Settings
set_target_properties(${PROJECT_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Out"
)