/**
 * @file mooncake_log_signal.h
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2025-08-14
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include <functional>
#include <vector>
#include <mutex>
#include <algorithm>

namespace mclog {

/**
 * @brief Observer pattern like godot's signal
 *
 * @tparam T
 */
template <typename... Args>
class Signal {
public:
    using SlotType = std::function<void(Args...)>;

    size_t connect(const SlotType& slot)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        size_t id = ++_lastId;
        _slots.push_back({id, slot});
        return id;
    }

    void disconnect(size_t id)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _slots.erase(std::remove_if(_slots.begin(), _slots.end(), [id](auto& pair) { return pair.first == id; }),
                     _slots.end());
    }

    void emit(Args... args)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        for (auto& [id, slot] : _slots) {
            slot(args...);
        }
    }

private:
    std::vector<std::pair<size_t, SlotType>> _slots;
    size_t _lastId = 0;
    std::mutex _mutex;
};

template <>
class Signal<void> : public Signal<> {
};

} // namespace mclog