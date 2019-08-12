cmake_minimum_required(VERSION 3.1)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14) 

project(BuildProjects)

# For vim-ycm
set( CMAKE_EXPORT_COMPILE_COMMANDS ON ) 

file(GLOB SRC_FILES "*")

add_executable(
    FlappyBird # executable file name
    ${SRC_FILES}
)

# Linking SFML
file(GLOB SFML "SFML/lib/*.dylib")
target_link_libraries(FlappyBird ${SFML})

