/**
 * @file mooncake_log.cpp
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "mooncake_log.h"
#include <chrono>
#include <ctime>

using namespace Mooncake;

#define COLOR_INFO fg(fmt::terminal_color::green)
#define COLOR_WARN fg(fmt::terminal_color::yellow)
#define COLOR_ERROR fg(fmt::terminal_color::red)

static bool _enable_time_tag = true;

void mclog::setTimeTagEnable(bool enable)
{
    _enable_time_tag = enable;
}

void mclog::internal::printf_tag_time()
{
    if (!_enable_time_tag) {
        return;
    }

    auto time = std::time(NULL);
    auto tm = std::localtime(&time);
    fmt::print("[{}] ", std::chrono::system_clock::now());
}

void mclog::internal::print_tag_info()
{
    fmt::print("[");
    fmt::print(COLOR_INFO, "info");
    fmt::print("] ");
}

void mclog::internal::print_tag_warn()
{
    fmt::print("[");
    fmt::print(COLOR_WARN, "warn");
    fmt::print("] ");
}

void mclog::internal::print_tag_error()
{
    fmt::print("[");
    fmt::print(COLOR_ERROR, "error");
    fmt::print("] ");
}
