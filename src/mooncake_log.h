/**
 * @file mc_log.h
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once
#include "fmt/base.h"
#include "fmt/color.h"
#include "fmt/format.h"
#include "fmt/ranges.h"
#include "fmt/chrono.h"
#include "signal.h"

namespace mclog {

enum LogLevel_t {
    level_info = 0,
    level_warn,
    level_error,
    level_debug,
};

enum TimeFormat_t {
    time_format_none = 0,
    time_format_full,
    time_format_time_only,
    time_format_unix_seconds,
    time_format_unix_milliseconds,
};

struct Settings_t {
    bool enable_level_tag = true;
    LogLevel_t log_level = level_error;
    TimeFormat_t time_format = time_format_full;
};

namespace internal {
void print_tag_time();
void print_tag_level(const LogLevel_t& level);
bool should_i_go(const LogLevel_t& level);
} // namespace internal

/**
 * @brief On log signal.
 *
 */
extern Signal<LogLevel_t, std::string> on_log;

/**
 * @brief Get logging settings.
 *
 * @return Settings_t&
 */
Settings_t& get_settings();

/**
 * @brief Set logging level.
 *
 * @param level
 */
void set_level(LogLevel_t level);

/**
 * @brief Set time format.
 *
 * @param format
 */
void set_time_format(TimeFormat_t format);

/**
 * @brief Log info
 *
 * @tparam Args
 * @param args
 */
template <typename... Args>
void info(fmt::format_string<Args...> fmt, Args&&... args)
{
    if (internal::should_i_go(level_info)) {
        return;
    }

    internal::print_tag_time();
    internal::print_tag_level(level_info);
    fmt::println(fmt, std::forward<Args>(args)...);

    on_log.emit(level_info, fmt::format(fmt, std::forward<Args>(args)...));
}

/**
 * @brief Log warning
 *
 * @tparam Args
 * @param args
 */
template <typename... Args>
void warn(fmt::format_string<Args...> fmt, Args&&... args)
{
    if (internal::should_i_go(level_warn)) {
        return;
    }

    internal::print_tag_time();
    internal::print_tag_level(level_warn);
    fmt::println(fmt, std::forward<Args>(args)...);

    on_log.emit(level_warn, fmt::format(fmt, std::forward<Args>(args)...));
}

/**
 * @brief Log error
 *
 * @tparam Args
 * @param args
 */
template <typename... Args>
void error(fmt::format_string<Args...> fmt, Args&&... args)
{
    if (internal::should_i_go(level_error)) {
        return;
    }

    internal::print_tag_time();
    internal::print_tag_level(level_error);
    fmt::println(fmt, std::forward<Args>(args)...);

    on_log.emit(level_error, fmt::format(fmt, std::forward<Args>(args)...));
}

/**
 * @brief Log debug
 *
 * @tparam Args
 * @param args
 */
template <typename... Args>
void debug(fmt::format_string<Args...> fmt, Args&&... args)
{
    if (internal::should_i_go(level_debug)) {
        return;
    }

    internal::print_tag_time();
    internal::print_tag_level(level_debug);
    fmt::println(fmt, std::forward<Args>(args)...);

    on_log.emit(level_debug, fmt::format(fmt, std::forward<Args>(args)...));
}

} // namespace mclog