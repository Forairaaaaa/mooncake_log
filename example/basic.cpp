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

using namespace mooncake;

int main()
{
    mclog::info("啊？？ {} ..??? 0x{:02X}", 114514, 66);
    mclog::info("{}", std::vector<int>{1, 23, 4, 5});
    // [11:45:14] [info] 啊？？ 114514 ..??? 0x42
    // [11:45:14] [info] [1, 23, 4, 5]

    mclog::warn("啊？？");
    mclog::warn("{}", "6");
    // [11:45:14] [warn] 啊？？
    // [11:45:14] [warn] 6

    mclog::error("啊？？");
    mclog::error("{}", "6");
    // [11:45:14] [error] 啊？？
    // [11:45:14] [error] 6

    mclog::set_time_tag_enable(false);
    mclog::tagInfo("我是沙比", "啊？？");
    mclog::tagInfo("我是沙比", "6");
    // [我是沙比] [info] 啊？？
    // [我是沙比] [info]  6

    // 注册 OnLog 回调
    mclog::add_on_log_callback([](mclog::LogLevel_t level, std::string msg) {
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

    return 0;
}
