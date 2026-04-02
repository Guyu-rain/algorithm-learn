#include <tuple>
#include <iostream>
#include <numbers>

std::tuple<int, int, int> func(int x, int y, int z) {
    return std::make_tuple(x, y, z); // 函数返回值为tuple时，`return {x, y, z}`等价
                                    // 如果函数返回值为auto，可能有报错
}

int main() {
    // 初始化
    std::tuple<int, double, std::string> t{1, std::numbers::pi, "hello world"};

    // 访问方式
    // 1. std::get<模板参数>(tuple) 【少用】
    int a = std::get<0>(t);
    double b = std::get<1>(t);
    std::string c = std::get<2>(t);

    // 2. 结构化绑定
    auto [x, y, z] = t; // x, y, z 都是拷贝
    auto& [x_, y_, z_] = t; // x_, y_, z_ 都是引用
    // 不允许 auto [&x, y, z]

    // 函数返回
    std::tuple<int, int, int> tuple = func(1, 2, 3);

    return 0;
}