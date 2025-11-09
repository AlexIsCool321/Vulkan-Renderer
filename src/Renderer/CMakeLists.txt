cmake_minimum_required(VERSION 3.10)
project(Renderer)


# Sources
file(GLOB_RECURSE SOURCE "*.cpp" "*.h")


# Library
add_library(${PROJECT_NAME} SHARED ${SOURCE})


# Settings
set_target_properties(${PROJECT_NAME} PROPERTIES
	# Linux
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Out/Bin"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Out/Bin"

	# Windows
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Out/Bin"
)