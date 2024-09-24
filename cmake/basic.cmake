project(AAA)

# Src files
file(GLOB_RECURSE AAA_SRCS
    ${AAA_ROOT_DIR}/src/*.c
    ${AAA_ROOT_DIR}/src/*.cpp
)
# Include
set(AAA_INCS
    ${AAA_ROOT_DIR}/src/
)


add_library(${PROJECT_NAME} ${AAA_SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC ${AAA_INCS})


option(AAA_BUILD_EXAMPLE "Build example" ON)


# Example
if(AAA_BUILD_EXAMPLE)
    add_subdirectory(./example/)
endif()

# CTest
enable_testing()
add_test(basic example/basic)
