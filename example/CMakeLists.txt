# Basic
add_executable(basic ./basic.cpp)
target_link_libraries(basic ${PROJECT_NAME})

# fmt native api
add_executable(fmt_native ./fmt_native.cpp)
target_link_libraries(fmt_native ${PROJECT_NAME})
