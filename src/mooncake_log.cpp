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

#define COLOR_INFO fg(fmt::color::green)
#define COLOR_WARN fg(fmt::color::gold)
#define COLOR_ERROR fg(fmt::color::red)

static bool _enable_time_tag = true;

void mclog::setTimeTagEnable(bool enable) { _enable_time_tag = enable; }

void mclog::_printf_tag_time()
{
    if (!_enable_time_tag)
        return;

    fmt::print("[{:%H:%M:%S}] ",
               std::chrono::round<std::chrono::seconds>(std::chrono::system_clock::now()));
}

void mclog::_print_tag_info()
{
    _printf_tag_time();
    fmt::print(COLOR_INFO, "[info] ");
}

void mclog::_print_tag_warn()
{
    _printf_tag_time();
    fmt::print(COLOR_WARN, "[warn] ");
}

void mclog::_print_tag_error()
{
    _printf_tag_time();
    fmt::print(COLOR_ERROR, "[error] ");
}
