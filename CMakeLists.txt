cmake_minimum_required(VERSION 3.22)
project(Misc)

file(GLOB SRC_FILES 
  Buffer/_internal/*.cpp
)
add_library(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)