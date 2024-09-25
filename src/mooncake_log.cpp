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

using namespace Mooncake;

#define COLOR_INFO fg(fmt::color::yellow_green)
#define COLOR_WARN fg(fmt::color::gold)
#define COLOR_ERROR fg(fmt::color::orange_red)

static bool _enable_time_tag = true;

void mclog::setTimeTagEnable(bool enable)
{
    _enable_time_tag = enable;
}

void mclog::internal::printf_tag_time()
{
    if (!_enable_time_tag)
        return;

    fmt::print("[{:%H:%M:%S}] ", std::chrono::round<std::chrono::seconds>(std::chrono::system_clock::now()));
}

void mclog::internal::print_tag_info()
{
    fmt::print(COLOR_INFO, "[I] ");
}

void mclog::internal::print_tag_warn()
{
    fmt::print(COLOR_WARN, "[W] ");
}

void mclog::internal::print_tag_error()
{
    fmt::print(COLOR_ERROR, "[E] ");
}
