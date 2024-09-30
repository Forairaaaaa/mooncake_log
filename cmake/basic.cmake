project(mooncake_log)

cmake_policy(SET CMP0077 NEW)

# Src files
file(GLOB_RECURSE MOONCAKE_LOG_SRCS
    ${MOONCAKE_LOG_ROOT_DIR}/src/*.c
    ${MOONCAKE_LOG_ROOT_DIR}/src/*.cc
    ${MOONCAKE_LOG_ROOT_DIR}/src/*.cpp
)
# Include
set(MOONCAKE_LOG_INCS
    ${MOONCAKE_LOG_ROOT_DIR}/src/
)


add_library(${PROJECT_NAME} ${MOONCAKE_LOG_SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC ${MOONCAKE_LOG_INCS})


option(MOONCAKE_LOG_BUILD_EXAMPLE "Build example" ON)


# Example
if(MOONCAKE_LOG_BUILD_EXAMPLE)
    add_subdirectory(./example/)
endif()

# CTest
enable_testing()
add_test(basic example/basic)
add_test(fmt_native example/fmt_native)
