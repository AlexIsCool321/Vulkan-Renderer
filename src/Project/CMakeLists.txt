cmake_minimum_required(VERSION 3.10)
project(Project)


# Sources
file(GLOB_RECURSE SOURCE "*.cpp" "*.h")


# Executable
add_executable(${PROJECT_NAME} ${SOURCE})


# Settings
set_target_properties(${PROJECT_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Out"
)