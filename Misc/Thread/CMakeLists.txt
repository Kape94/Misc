set(SRC_FILES 
  _internal/TaskQueue.cpp
  _internal/ThreadPool.cpp
  _internal/ThreadPoolWorker.cpp
)

set(TARGET_NAME MiscThread)
add_library(${TARGET_NAME} ${SRC_FILES})

target_compile_features(${TARGET_NAME} PRIVATE cxx_std_17)

target_include_directories(${TARGET_NAME} PRIVATE ${MISC_ROOT})