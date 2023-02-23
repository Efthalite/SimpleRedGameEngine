cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project("GameEngine1")


file(GLOB_RECURSE CPP_FILES "src/*.cpp")
file(COPY "src/shaders/" DESTINATION "shaders")
file(COPY "src/assets/" DESTINATION "assets")


add_executable(${PROJECT_NAME} ${CPP_FILES})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory("external/glad")
target_link_libraries(${PROJECT_NAME} PRIVATE glad)





add_subdirectory("external/glfw")
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

add_subdirectory("external/glm")
target_link_libraries(${PROJECT_NAME} PRIVATE glm)

add_subdirectory("external/stb")
target_link_libraries(${PROJECT_NAME} PRIVATE stb)





