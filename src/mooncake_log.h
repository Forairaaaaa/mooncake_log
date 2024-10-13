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
#include <utility>
#include <functional>

namespace mooncake {
namespace mclog {

enum LogLevel_t {
    level_info = 0,
    level_warn,
    level_error,
};

namespace internal {
void printf_tag_time();
void print_tag_info();
void print_tag_warn();
void print_tag_error();
bool is_on_log_callback_exist();
void invoke_on_log_callbacks(LogLevel_t level, std::string msg);
} // namespace internal

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

    if (internal::is_on_log_callback_exist()) {
        internal::invoke_on_log_callbacks(level_info, fmt::format(fmt, std::forward<Args>(args)...));
    }
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

    if (internal::is_on_log_callback_exist()) {
        internal::invoke_on_log_callbacks(level_warn, fmt::format(fmt, std::forward<Args>(args)...));
    }
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

    if (internal::is_on_log_callback_exist()) {
        internal::invoke_on_log_callbacks(level_error, fmt::format(fmt, std::forward<Args>(args)...));
    }
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

    if (internal::is_on_log_callback_exist()) {
        internal::invoke_on_log_callbacks(level_info, fmt::format(fmt, std::forward<Args>(args)...));
    }
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

    if (internal::is_on_log_callback_exist()) {
        internal::invoke_on_log_callbacks(level_warn, fmt::format(fmt, std::forward<Args>(args)...));
    }
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

    if (internal::is_on_log_callback_exist()) {
        internal::invoke_on_log_callbacks(level_error, fmt::format(fmt, std::forward<Args>(args)...));
    }
}

/* -------------------------------------------------------------------------- */
/*                                  Callbacks                                 */
/* -------------------------------------------------------------------------- */
typedef std::function<void(LogLevel_t, std::string)> onLogCallback_t;

void add_on_log_callback(onLogCallback_t callback);

void remove_on_log_callbacks();

/* -------------------------------------------------------------------------- */
/*                                  Settings                                  */
/* -------------------------------------------------------------------------- */
void set_time_tag_enable(bool enable);

}; // namespace mclog
} // namespace mooncake
