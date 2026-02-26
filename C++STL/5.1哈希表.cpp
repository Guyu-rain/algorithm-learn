#include <unordered_map>
#include <string>
#include <iostream>

// ----- 初始化 -----
// <键, 值>对
std::unordered_map<int, std::string> hashmap;
std::unordered_map<int, std::string> hashmap{{1, "one"}, {2, "two"}, {3, "three"}};

// ----- 常用方法 -----
using namespace std;

// 需要特别注意的是，访问一个不存在的键，会自动创建这个键，对应的值是默认构造的值(如 int 为 0)
// 所以需要先判断hashmap.contains(`key`)，然后在进行查询等操作

// unordered_map<K, V> 的每一个元素都是 pair<K, V>
int main() {
    unordered_map<int, string> hashmap{{1, "one"}, {2, "two"}, {3, "three"}};

    // 检查哈希表是否为空
    cout << hashmap.empty() << endl;

    // 获取哈希表的大小
    cout << hashmap.size() << endl;

    // 查找指定键是否存在
    // 注意：contains 方法C++20之后才有，之前使用`hashmap.count(2) > 0`
    if (hashmap.contains(2)) {
        cout << "Key 2 -> " << hashmap[2] << endl;
    } else {
        cout << "Key 2 not found." << endl;
    }

    // 获取指定键对应的值，若不存在返回默认构造的值
    // 输出空字符串
    cout << hashmap[4] << endl;

    // 插入一个新的键值对
    hashmap[4] = "four";

    // 获取这个键值对的值
    cout << hashmap[4] << endl;

    // 删除键值对
    hashmap.erase(3);

    // 检查删除后键 3 是否存在
    if (hashmap.contains(3)) {
        cout << "Key 3 -> " << hashmap[3] << endl;
    } else {
        cout << "Key 3 not found." << endl;
    }

    // 遍历哈希表 - 乱序
    for (const auto &pair: hashmap) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // 注意：访问某个不存在的键会自动创建这个键
    unordered_map<int, string> hashmap2;

    // 键值对的数量是 0
    cout << hashmap2.size() << endl;

    // 访问不存在的键，会直接创建一个键，对应的值是默认构造的值
    cout << hashmap2[1] << endl;
    cout << hashmap2[2] << endl;
    
    cout << hashmap2.size() << endl; // 2
    
    return 0;
}