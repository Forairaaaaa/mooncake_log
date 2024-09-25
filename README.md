# Mooncake Log
只是 [fmt](https://github.com/fmtlib/fmt) 的简单封装

```cpp
mclog::info("啊？？ {} ..??? 0x{:02X}", 114514, 66);
mclog::info("{}", std::vector<int>{1, 23, 4, 5});
// [11:45:14] [I] 啊？？ 114514 ..??? 0x42
// [11:45:14] [I] [1, 23, 4, 5]

mclog::warn("啊？？");
mclog::warn("{}", "6");
// [11:45:14] [W] 啊？？
// [11:45:14] [W] 6

mclog::error("啊？？");
mclog::error("{}", "6");
// [11:45:14] [E] 啊？？
// [11:45:14] [E] 6

mclog::setTimeTagEnable(false);
mclog::tagInfo("我是沙比", "啊？？");
mclog::tagInfo("我是沙比", "6");
// [我是沙比] [I] 啊？？
// [我是沙比] [I]  6
```

