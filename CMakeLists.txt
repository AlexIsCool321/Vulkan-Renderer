cmake_minimum_required(VERSION 3.10)
project(Vulkan_Renderer)

include_directories("src/Renderer/Headers")

add_subdirectory(src/Renderer)
add_subdirectory(src/Project)