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

void basic_logging()
{
    fmt::println("basic logging:");

    mclog::info("?? {} ..??? 0x{:02X}", 114514, 66);
    // [2025-06-06 12.34.56.123] [info] ?? 114514 ..??? 0x42

    mclog::info("{}", std::vector<int>{1, 23, 4, 5});
    // [2025-06-06 12.34.56.123] [info] [1, 23, 4, 5]

    mclog::warn("???");
    // [2025-06-06 12.34.56.123] [warn] ???

    mclog::warn("{}", "6");
    // [2025-06-06 12.34.56.123] [warn] 6

    mclog::error("???");
    // [2025-06-06 12.34.56.123] [error] ???

    mclog::error("{}", "6");
    // [2025-06-06 12.34.56.123] [error] 6

    fmt::println("");
}

void logging_level()
{
    fmt::println("logging level:");

    mclog::debug("you can't see me now");
    // > no shit
    mclog::set_level(mclog::level_debug);
    mclog::debug("dddddddddddddddeeeeeeeeeebuggggggggggggggggggiiiinnnnnnggg");
    // [2025-06-06 12.34.56.123] [debug] dddddddddddddddeeeeeeeeeebuggggggggggggggggggiiiinnnnnnggg

    fmt::println("");
}

void time_tag_format()
{
    fmt::println("time tag format:");

    mclog::set_time_format(mclog::time_format_none);
    mclog::info("time format: none");
    // [info] time format: none

    mclog::set_time_format(mclog::time_format_time_only);
    mclog::info("time format: time only");
    // [12.34.56.123] [info] time format: time only

    mclog::set_time_format(mclog::time_format_unix_seconds);
    mclog::info("time format: unix seconds");
    // [1752825074] [info] time format: unix seconds

    mclog::set_time_format(mclog::time_format_unix_milliseconds);
    mclog::info("time format: unix milliseconds");
    // [1752825074337] [info] time format: unix milliseconds

    mclog::set_time_format(mclog::time_format_full);
    mclog::info("time format: full (default)");
    // [2025-06-06 12.34.56.123] [info] time format: full (default)

    fmt::println("");
}

void level_tag_format()
{
    fmt::println("level tag format:");

    mclog::set_level_tag_format(mclog::level_format_none);
    mclog::info("level tag format: none");
    // [2025-06-06 12.34.56.123] [info] level tag format: none

    mclog::set_level_tag_format(mclog::level_format_uppercase);
    mclog::info("level tag format: uppercase");
    // [2025-06-06 12.34.56.123] [INFO] level tag format: uppercase

    mclog::set_level_tag_format(mclog::level_format_single_letter);
    mclog::info("level tag format: single letter");
    // [2025-06-06 12.34.56.123] [I] level tag format: single letter

    mclog::set_level_tag_format(mclog::level_format_lowercase);
    mclog::info("level tag format: lowercase (default)");
    // [2025-06-06 12.34.56.123] [info] level tag format: lowercase (default)

    fmt::println("");
}

void on_log_callback()
{
    fmt::println("on log callback:");

    mclog::on_log.connect([](mclog::LogLevel_t level, const std::string& msg) {
        fmt::println(">> level: {} msg: {}", static_cast<int>(level), msg);
    });

    mclog::info("?");
    // [2025-06-06 12.34.56.123]  [info] ?
    // >> level: 0 msg: ?

    mclog::warn("?");
    // [2025-06-06 12.34.56.123] [warn] ?
    // >> level: 1 msg: ?

    mclog::error("?");
    // [2025-06-06 12.34.56.123] [error] ?
    // >> level: 2 msg: ?

    mclog::debug("?");
    // [2025-06-06 12.34.56.123] [debug] ?
    // >> level: 3 msg: ?

    mclog::on_log.clear();
    mclog::info("clear on log callback");
    // [2025-06-06 12.34.56.123] [info] clear on log callback

    fmt::println("");
}

int main()
{
    basic_logging();
    logging_level();
    time_tag_format();
    level_tag_format();
    on_log_callback();
    return 0;
}
