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

namespace internal {
void printf_tag_time();
void print_tag_info();
void print_tag_warn();
void print_tag_error();
void print_tag_debug();
} // namespace internal

/* -------------------------------------------------------------------------- */
/*                                  Callback                                  */
/* -------------------------------------------------------------------------- */
extern Signal<LogLevel_t, std::string> on_log_signal;

/* -------------------------------------------------------------------------- */
/*                                   Logging                                  */
/* -------------------------------------------------------------------------- */

/**
 * @brief Log info
 *
 * @tparam Args
 * @param args
 */
template <typename... Args>
void info(fmt::format_string<Args...> fmt, Args&&... args)
{
    internal::printf_tag_time();
    internal::print_tag_info();
    fmt::println(fmt, std::forward<Args>(args)...);

    on_log_signal.emit(level_info, fmt::format(fmt, std::forward<Args>(args)...));
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
    internal::printf_tag_time();
    internal::print_tag_warn();
    fmt::println(fmt, std::forward<Args>(args)...);

    on_log_signal.emit(level_warn, fmt::format(fmt, std::forward<Args>(args)...));
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
    internal::printf_tag_time();
    internal::print_tag_error();
    fmt::println(fmt, std::forward<Args>(args)...);

    on_log_signal.emit(level_error, fmt::format(fmt, std::forward<Args>(args)...));
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
    internal::printf_tag_time();
    internal::print_tag_debug();
    fmt::println(fmt, std::forward<Args>(args)...);

    on_log_signal.emit(level_debug, fmt::format(fmt, std::forward<Args>(args)...));
}

/**
 * @brief Log info with a custom tag
 *
 * @tparam Args
 * @param customTag
 * @param fmt
 * @param args
 */
template <typename... Args>
void tagInfo(const std::string& customTag, fmt::format_string<Args...> fmt, Args&&... args)
{
    internal::printf_tag_time();
    internal::print_tag_info();
    fmt::print("[{}] ", customTag);
    fmt::println(fmt, std::forward<Args>(args)...);

    on_log_signal.emit(level_info, fmt::format(fmt, std::forward<Args>(args)...));
}

/**
 * @brief Log warning with a custom tag
 *
 * @tparam Args
 * @param customTag
 * @param fmt
 * @param args
 */
template <typename... Args>
void tagWarn(const std::string& customTag, fmt::format_string<Args...> fmt, Args&&... args)
{
    internal::printf_tag_time();
    internal::print_tag_warn();
    fmt::print("[{}] ", customTag);
    fmt::println(fmt, std::forward<Args>(args)...);

    on_log_signal.emit(level_warn, fmt::format(fmt, std::forward<Args>(args)...));
}

/**
 * @brief Log error with a custom tag
 *
 * @tparam Args
 * @param customTag
 * @param fmt
 * @param args
 */
template <typename... Args>
void tagError(const std::string& customTag, fmt::format_string<Args...> fmt, Args&&... args)
{
    internal::printf_tag_time();
    internal::print_tag_error();
    fmt::print("[{}] ", customTag);
    fmt::println(fmt, std::forward<Args>(args)...);

    on_log_signal.emit(level_error, fmt::format(fmt, std::forward<Args>(args)...));
}

/**
 * @brief Log debug with a custom tag
 *
 * @tparam Args
 * @param customTag
 * @param fmt
 * @param args
 */
template <typename... Args>
void tagDebug(const std::string& customTag, fmt::format_string<Args...> fmt, Args&&... args)
{
    internal::printf_tag_time();
    internal::print_tag_debug();
    fmt::print("[{}] ", customTag);
    fmt::println(fmt, std::forward<Args>(args)...);

    on_log_signal.emit(level_debug, fmt::format(fmt, std::forward<Args>(args)...));
}

/* -------------------------------------------------------------------------- */
/*                                  Settings                                  */
/* -------------------------------------------------------------------------- */
void set_time_tag_enable(bool enable);

}; // namespace mclog
