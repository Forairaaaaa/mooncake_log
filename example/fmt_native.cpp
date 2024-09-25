/**
 * @file fmt_native.cpp
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <fmt/base.h>
#include <fmt/format.h>
#include <fmt/chrono.h>
#include <fmt/ranges.h>
#include <fmt/color.h>
#include <iostream>
#include <vector>
// https://github.com/fmtlib/fmt

int main()
{
    fmt::print("Hello, world!\n");

    std::string s = fmt::format("The answer is {}.", 42);
    // s == "The answer is 42."
    std::cout << s << std::endl;

    s = fmt::format("I'd rather be {1} than {0}.", "right", "happy");
    // s == "I'd rather be happy than right."
    std::cout << s << std::endl;

    auto now = std::chrono::system_clock::now();
    fmt::print("Date and time: {}\n", now);
    fmt::print("Time: {:%H:%M}\n", now);

    std::vector<int> v = {1, 2, 3};
    fmt::print("{}\n", v);

    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "Hello, {}!\n", "world");
    fmt::print(fg(fmt::color::floral_white) | bg(fmt::color::slate_gray) | fmt::emphasis::underline, "Olá, {}!\n",
               "Mundo");
    fmt::print(fg(fmt::color::steel_blue) | fmt::emphasis::italic, "你好{}！\n", "世界");

    return 0;
}
