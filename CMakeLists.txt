cmake_minimum_required(VERSION 3.12)

set(MOONCAKE_LOG_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

if (ESP_PLATFORM)
    include(${CMAKE_CURRENT_LIST_DIR}/cmake/esp_idf.cmake)
else()
    include(${CMAKE_CURRENT_LIST_DIR}/cmake/basic.cmake)
endif()
