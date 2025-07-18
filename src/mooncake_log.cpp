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
#include <functional>
#include <vector>

#define COLOR_INFO  fg(fmt::terminal_color::green)
#define COLOR_WARN  fg(fmt::terminal_color::yellow)
#define COLOR_ERROR fg(fmt::terminal_color::red)
#define COLOR_DEBUG fg(fmt::terminal_color::blue)

mclog::Signal<mclog::LogLevel_t, std::string> mclog::on_log;

static mclog::Settings_t _settings;

mclog::Settings_t& mclog::get_settings()
{
    return _settings;
}

void mclog::set_level(LogLevel_t level)
{
    get_settings().log_level = level;
}

void mclog::set_time_format(TimeFormat_t format)
{
    get_settings().time_format = format;
}

bool mclog::internal::should_i_go(const LogLevel_t& level)
{
    return level > get_settings().log_level;
}

void mclog::internal::print_tag_time()
{
    if (_settings.time_format == TimeFormat_t::time_format_none) {
        return;
    }

    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    switch (_settings.time_format) {
        case TimeFormat_t::time_format_full:
            fmt::print("[{:04}-{:02}-{:02} {:02}:{:02}:{:02}.{:03}] ",
                       std::localtime(&now_c)->tm_year + 1900, // 年份
                       std::localtime(&now_c)->tm_mon + 1,     // 月
                       std::localtime(&now_c)->tm_mday,        // 日
                       std::localtime(&now_c)->tm_hour,        // 时
                       std::localtime(&now_c)->tm_min,         // 分
                       std::localtime(&now_c)->tm_sec,         // 秒
                       milliseconds.count());                  // 毫秒
            break;

        case TimeFormat_t::time_format_time_only:
            fmt::print("[{:02}:{:02}:{:02}.{:03}] ",
                       std::localtime(&now_c)->tm_hour, // 时
                       std::localtime(&now_c)->tm_min,  // 分
                       std::localtime(&now_c)->tm_sec,  // 秒
                       milliseconds.count());           // 毫秒
            break;

        case TimeFormat_t::time_format_unix_seconds:
            fmt::print("[{}] ", std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count());
            break;

        case TimeFormat_t::time_format_unix_milliseconds:
            fmt::print("[{}] ", std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count());
            break;

        default:
            fmt::print("[wtf] ");
            break;
    }
}

void mclog::internal::print_tag_level(const LogLevel_t& level)
{
    if (!_settings.enable_level_tag) {
        return;
    }

    fmt::print("[");

    switch (level) {
        case LogLevel_t::level_info:
            fmt::print(COLOR_INFO, "info");
            break;
        case LogLevel_t::level_warn:
            fmt::print(COLOR_WARN, "warn");
            break;
        case LogLevel_t::level_error:
            fmt::print(COLOR_ERROR, "error");
            break;
        case LogLevel_t::level_debug:
            fmt::print(COLOR_DEBUG, "debug");
            break;
        default:
            fmt::print(COLOR_DEBUG, "wtf");
            break;
    }

    fmt::print("] ");
}
