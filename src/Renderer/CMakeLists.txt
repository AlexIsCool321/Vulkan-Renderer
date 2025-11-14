cmake_minimum_required(VERSION 3.10)
project(Renderer)


# Packages
find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)


# Third Party
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${Vulkan_INCLUDE_DIRS})


# Sources
file(GLOB_RECURSE SOURCE "*.cpp" "*.h")


# Library
add_library(${PROJECT_NAME} SHARED ${SOURCE})


# Libraries
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)


# Settings
set_target_properties(${PROJECT_NAME} PROPERTIES
	# Linux
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Out/Bin"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Out/Bin"

	# Windows
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Out/Bin"
)