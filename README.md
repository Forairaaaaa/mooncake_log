# Mooncake Log
[spdlog](https://github.com/gabime/spdlog) 青春版，只是 [fmt](https://github.com/fmtlib/fmt) 库的简单封装

```cpp
mclog::info("啊？？ {} ..??? 0x{:02X}", 114514, 66);
mclog::info("{}", std::vector<int>{1, 23, 4, 5});
// [15:26:06] [info] 啊？？ 114514 ..??? 0x42
// [15:26:06] [info] [1, 23, 4, 5]

mclog::warn("啊？？");
mclog::warn("{}", "6");
// [15:26:42] [warn] 啊？？
// [15:26:42] [warn] 6

mclog::error("啊？？");
mclog::error("{}", "6");
// [15:26:42] [error] 啊？？
// [15:26:42] [error] 6

mclog::tagInfo("我是沙比", "啊？？");
mclog::tagInfo("我是沙比", "6");
// [15:27:40] [info] [我是沙比] 啊？？
// [15:27:40] [info] [我是沙比] 6
```

