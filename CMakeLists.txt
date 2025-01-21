cmake_minimum_required(VERSION 3.22)
project(Misc)

file(GLOB SRC_FILES 
  Buffer/_internal/*.cpp
  Thread/_internal/*.cpp
)
add_library(${PROJECT_NAME} ${SRC_FILES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)