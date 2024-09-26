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
#include "fmt/ranges.h"
#include "fmt/chrono.h"
#include <utility>

namespace Mooncake {
namespace mclog {
namespace internal {
void printf_tag_time();
void print_tag_info();
void print_tag_warn();
void print_tag_error();
} // namespace internal

/**
 * @brief Log info
 *
 * @tparam Args
 * @param args
 */
template <typename... Args> void info(Args &&... args)
{
    internal::printf_tag_time();
    internal::print_tag_info();
    fmt::println(std::forward<Args>(args)...);
}

/**
 * @brief Log warning
 *
 * @tparam Args
 * @param args
 */
template <typename... Args> void warn(Args &&... args)
{
    internal::printf_tag_time();
    internal::print_tag_warn();
    fmt::println(std::forward<Args>(args)...);
}

/**
 * @brief Log error
 *
 * @tparam Args
 * @param args
 */
template <typename... Args> void error(Args &&... args)
{
    internal::printf_tag_time();
    internal::print_tag_error();
    fmt::println(std::forward<Args>(args)...);
}

/**
 * @brief Log info with a custom tag
 *
 * @tparam Args
 * @param customTag
 * @param args
 */
template <typename... Args> void tagInfo(const std::string &customTag, Args &&... args)
{
    internal::printf_tag_time();
    fmt::print("[{}] ", customTag);
    internal::print_tag_info();
    fmt::println(std::forward<Args>(args)...);
}

/**
 * @brief Log warning with a custom tag
 *
 * @tparam Args
 * @param customTag
 * @param args
 */
template <typename... Args> void tagWarn(const std::string &customTag, Args &&... args)
{
    internal::printf_tag_time();
    fmt::print("[{}] ", customTag);
    internal::print_tag_warn();
    fmt::println(std::forward<Args>(args)...);
}

/**
 * @brief Log error with a custom tag
 *
 * @tparam Args
 * @param customTag
 * @param args
 */
template <typename... Args> void tagError(const std::string &customTag, Args &&... args)
{
    internal::printf_tag_time();
    fmt::print("[{}] ", customTag);
    internal::print_tag_error();
    fmt::println(std::forward<Args>(args)...);
}

/* --------------------------------- Setting -------------------------------- */
void set_time_tag_enable(bool enable);
}; // namespace mclog
} // namespace Mooncake
