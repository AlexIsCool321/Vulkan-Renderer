cmake_minimum_required(VERSION 3.10)
project(Vulkan_Renderer)

# Third Party
include_directories("src/Third Party/GLM/Headers")


# Headers
include_directories("src/Renderer/Headers")
include_directories("src/Project/Headers")


# Subsystems
add_subdirectory(src/Renderer)
add_subdirectory(src/Project)