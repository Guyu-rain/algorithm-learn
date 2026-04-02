#include <unordered_set>
#include <iostream>

// 底层是哈希表，存储不重复的元素
// 常见用法：对元素去重

// ----- 初始化 -----
std::unordered_set<int> uset;
std::unordered_set<int> uset{1, 2, 3, 4};

// ----- 常用方法 ------
using namespace std;
int main() {
    unordered_set<int> hashset{1, 2, 3, 4};

    // 检查是否为空
    cout << hashset.empty() << endl;

    // 查找指定元素是否存在 - contains() (after C++20)
    // C++20之前使用count() > 0
    if (hashset.contains(3)) {
        cout << "Element 3 found." << endl;
    } else {
        cout << "Element 3 not fount." << endl;
    }

    // 插入新元素
    hashset.insert(5);

    // 删除一个元素
    hashset.erase(2);

    // 遍历 - 顺序随机
    for (const auto &element : hashset) {
        cout << element << endl;
    }

    return 0;
}