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

using namespace mooncake;

#define COLOR_INFO  fg(fmt::terminal_color::green)
#define COLOR_WARN  fg(fmt::terminal_color::yellow)
#define COLOR_ERROR fg(fmt::terminal_color::red)

static bool _enable_time_tag = true;

void mclog::set_time_tag_enable(bool enable)
{
    _enable_time_tag = enable;
}

void mclog::internal::printf_tag_time()
{
    if (!_enable_time_tag) {
        return;
    }

    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    fmt::print("[{:04}-{:02}-{:02} {:02}:{:02}:{:02}.{:03}] ",
               std::localtime(&now_c)->tm_year + 1900, // 年份
               std::localtime(&now_c)->tm_mon + 1,     // 月
               std::localtime(&now_c)->tm_mday,        // 日
               std::localtime(&now_c)->tm_hour,        // 时
               std::localtime(&now_c)->tm_min,         // 分
               std::localtime(&now_c)->tm_sec,         // 秒
               milliseconds.count());                  // 毫秒
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

/* -------------------------------------------------------------------------- */
/*                                  Callbacks                                 */
/* -------------------------------------------------------------------------- */
static std::vector<mclog::onLogCallback_t>* _on_log_callback_list = nullptr;

bool mclog::internal::is_on_log_callback_exist()
{
    return _on_log_callback_list != nullptr;
}

void mclog::internal::invoke_on_log_callbacks(LogLevel_t level, std::string msg)
{
    if (_on_log_callback_list == nullptr) {
        return;
    }

    for (const auto& callback : *_on_log_callback_list) {
        callback(level, msg);
    }
}

void mclog::add_on_log_callback(onLogCallback_t callback)
{
    if (callback == nullptr) {
        return;
    }

    if (_on_log_callback_list == nullptr) {
        _on_log_callback_list = new std::vector<mclog::onLogCallback_t>;
    }

    _on_log_callback_list->push_back(callback);
}

void mclog::remove_on_log_callbacks()
{
    if (_on_log_callback_list == nullptr) {
        return;
    }
    delete _on_log_callback_list;
}
