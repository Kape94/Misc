set(SRC_FILES
    _internal/ChildProcess.cpp
)

set(TARGET_NAME MiscProcess)

add_library(${TARGET_NAME} 
    ${SRC_FILES}
)

target_compile_features(${TARGET_NAME} PRIVATE cxx_std_17)

target_include_directories(${TARGET_NAME} 
    PRIVATE 
        ${MISC_ROOT}
        ${CMAKE_CURRENT_SOURCE_DIR}
)
