#include <coroutine>
#include <iostream>
#include <future>

std::future<int> async_value(int value) {
    co_await std::chrono::seconds(1);
    co_return value * 2;
}

int main() {
    auto result = async_value(42);
    std::cout << "Result: " << result.get() << std::endl;
}

#include <algorithm>

#include <vector>

int main() {
    std::vector<int> v = { 5, 2, 8, 1, 9 };
    std::sort(v.begin(), v.end(), std::greater<int>());
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
