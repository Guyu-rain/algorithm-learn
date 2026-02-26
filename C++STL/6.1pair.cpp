#include <utility> // pair
#include <iostream>

std::pair<int, std::string> func(int x, std::string s) {
    return {x, s}; // 用 {} 打包
} 

int main() {
    // 初始化
    std::pair<int, std::string> p{1, "one"};

    // 访问方式
    int k = p.first;
    std::string v = p.second;
    
    // 结构化绑定
    auto [k, v] = p;
    
    // 函数返回
    std::pair<int, std::string> pair = func(1, "one");
    return 0;
}