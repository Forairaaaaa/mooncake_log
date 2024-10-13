# Mooncake Log
只是 [fmt](https://github.com/fmtlib/fmt) 的简单封装

```cpp
mclog::info("啊？？ {} ..??? 0x{:02X}", 114514, 66);
mclog::info("{}", std::vector<int>{1, 23, 4, 5});
// [2077-03-07 11:45:14.191] [info] 啊？？ 114514 ..??? 0x42
// [2077-03-07 11:45:14.191] [info] [1, 23, 4, 5]

mclog::warn("啊？？");
mclog::warn("{}", "6");
// [2077-03-07 11:45:14.191] [warn] 啊？？
// [2077-03-07 11:45:14.191] [warn] 6

mclog::error("啊？？");
mclog::error("{}", "6");
// [2077-03-07 11:45:14.191] [error] 啊？？
// [2077-03-07 11:45:14.191] [error] 6

mclog::set_time_tag_enable(false);
mclog::tagInfo("我是沙比", "啊？？");
mclog::tagInfo("我是沙比", "6");
// [info] [我是沙比] 啊？？
// [info] [我是沙比] 6

// 注册 OnLog 回调
mclog::add_on_log_callback([](mclog::LogLevel_t level, std::string msg) {
    fmt::println(">> level: {} msg: {}", static_cast<int>(level), msg);
});

mclog::info("?");
// [info] ?
// >> level: 0 msg: ?
```

