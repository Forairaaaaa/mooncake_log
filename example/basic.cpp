/**
 * @file basic.cpp
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "fmt/base.h"
#include <mooncake_log.h>
#include <vector>

int main()
{
    mclog::info("啊？？ {} ..??? 0x{:02X}", 114514, 66);
    mclog::info("{}", std::vector<int>{1, 23, 4, 5});
    // [2025-06-06 12.34.56.123] [info] 啊？？ 114514 ..??? 0x42
    // [2025-06-06 12.34.56.123] [info] [1, 23, 4, 5]

    mclog::warn("啊？？");
    mclog::warn("{}", "6");
    // [2025-06-06 12.34.56.123] [warn] 啊？？
    // [2025-06-06 12.34.56.123] [warn] 6

    mclog::error("啊？？");
    mclog::error("{}", "6");
    // [2025-06-06 12.34.56.123] [error] 啊？？
    // [2025-06-06 12.34.56.123] [error] 6

    mclog::debug("you can't see me now");
    mclog::set_level(mclog::LogLevel_t::level_debug);
    mclog::debug("dddddddddddddddeeeeeeeeeebuggggggggggggggggggiiiinnnnnnggg");
    // [2025-06-06 12.34.56.123] [debug] dddddddddddddddeeeeeeeeeebuggggggggggggggggggiiiinnnnnnggg

    mclog::set_time_format(mclog::time_format_time_only);
    mclog::info("time format: time only");
    // [12.34.56.123] [info] time format: time only

    mclog::set_time_format(mclog::time_format_ticks);
    mclog::info("time format: ticks");
    // [1752825074337] [info] time format: ticks

    mclog::set_time_format(mclog::time_format_none);
    mclog::info("time format: none");
    // [info] time format: none

    mclog::set_time_format(mclog::time_format_full);
    mclog::info("time format: full (default)");

    mclog::get_settings().enable_level_tag = false;
    mclog::info("????");
    // ????

    mclog::get_settings().enable_level_tag = true;

    // 注册 OnLog 回调
    mclog::on_log.connect([](mclog::LogLevel_t level, std::string msg) {
        fmt::println(">> level: {} msg: {}", static_cast<int>(level), msg);
    });

    mclog::info("?");
    // [info] ?
    // >> level: 0 msg: ?

    mclog::warn("?");
    // [warn] ?
    // >> level: 1 msg: ?

    mclog::error("?");
    // [error] ?
    // >> level: 2 msg: ?

    mclog::debug("?");
    // [debug] ?
    // >> level: 3 msg: ?

    return 0;
}
