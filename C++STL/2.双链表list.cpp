#include <list>
#include <iostream>

// ----- 初始化 -----
const int n = 10;

std::list<int> lst;
std::list<int> lst(n); // 初始化大小为 n , 链表中默认值均为 0

std::list<int> lst{1, 3, 5}; // 赋值初始化，聚合方法
std::list<int> lst = {1, 3, 5}; // 同上
std::list<int> lst = std::list{1, 3, 5}; // 同上

std::list<int> lst(n, 2);// 初始化一个大小为 n 的链表，值全部为 2

using namespace std;

int main() {
    list<int> list{1, 2, 3, 4, 5};
    
    // 检查链表是否为空
    cout << lst.empty() << endl; // 输出 false
    
    // 获取链表的大小
    cout << lst.size() << endl;

    // 头部操作 尾部操作
    // 1. 头插/尾插
    lst.push_front(0);
    lst.push_back(6);

    // 2. 获取头/尾元素
    cout << lst.front() << " " << lst.back() << endl;

    // 3. 头删/尾删
    lst.pop_front();
    lst.pop_back();

    // 插
    auto it = lst.begin();
    // 将迭代器 it 移动到第三个位置
    advance(it, 2);
    // 在第三个位置插入 99
    lst.insert(it, 99);

    // 删
    it = lst.begin();
    // 将迭代器 it 移动到第二个位置
    advance(it, 1);
    // 删除第二个节点
    lst.erase(it);

    // 遍历链表
    for (int val : lst) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}