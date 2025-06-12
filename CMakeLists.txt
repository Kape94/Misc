cmake_minimum_required(VERSION 3.22)
project(Misc)

set(MISC_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(Misc)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} 
  INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} 
  INTERFACE
    MiscBuffer
    MiscThread
    MiscMemoryPool
)

option(BUILD_SAMPLES OFF)
if (${BUILD_SAMPLES})
  add_subdirectory(Samples)
endif()