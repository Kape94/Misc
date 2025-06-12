add_executable(ex1-buffer ex1-buffer.cpp)
target_link_libraries(ex1-buffer Misc)

add_executable(ex2-memoryPool ex2-memoryPool.cpp)
target_link_libraries(ex2-memoryPool Misc)

add_executable(ex3-memoryPoolLoadTest ex3-memoryPoolLoadTest.cpp)
target_link_libraries(ex3-memoryPoolLoadTest Misc)

add_executable(ex4-threadPool ex4-threadPool.cpp)
target_link_libraries(ex4-threadPool Misc)
