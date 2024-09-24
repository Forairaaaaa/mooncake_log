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
#include <mooncake_log.h>
#include <vector>

using namespace Mooncake;

int main()
{
    mclog::info("啊？？ {} ..??? 0x{:02X}", 114514, 66);
    mclog::info("{}", std::vector<int>{1, 23, 4, 5});
    // 输出：
    // [15:26:06] [info] 啊？？ 114514 ..??? 0x42
    // [15:26:06] [info] [1, 23, 4, 5]

    mclog::warn("啊？？ {} ..??? 0x{:02X}", 114514, 66);
    mclog::warn("{}", std::vector<int>{1, 23, 4, 5});
    // 输出：
    // [15:26:42] [warn] 啊？？ 114514 ..??? 0x42
    // [15:26:42] [warn] [1, 23, 4, 5]

    mclog::error("啊？？ {} ..??? 0x{:02X}", 114514, 66);
    mclog::error("{}", std::vector<int>{1, 23, 4, 5});
    // 输出：
    // [15:26:42] [error] 啊？？ 114514 ..??? 0x42
    // [15:26:42] [error] [1, 23, 4, 5]

    mclog::tagInfo("我是沙比", "啊？？ {} ..??? 0x{:02X}", 114514, 66);
    mclog::tagInfo("我是沙比", "{}", std::vector<int>{1, 23, 4, 5});
    // 输出：
    // [15:27:40] [info] [我是沙比] 啊？？ 114514 ..??? 0x42
    // [15:27:40] [info] [我是沙比] [1, 23, 4, 5]

    return 0;
}
