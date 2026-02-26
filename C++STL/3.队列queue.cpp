#include <queue> // queue 是单向队列
#include <iostream>

using namespace std;

// 单向队列只能队尾push()，队头pop()；对头队尾都能查看front(), back()
int main() {
    // 初始化一个空整型队列
    queue<int> q;

    // 增 - 队尾
    q.push(10);
    q.push(20);
    q.push(30);

    // 检查队列是否为空
    cout << q.empty() << endl;

    // 获取队列的大小
    cout << q.size() << endl;

    // 获取队列的对头和队尾元素
    cout << q.front() << " " << q.back() << endl;

    // 删 - 队头
    q.pop();

    // 输出新的队头
    cout << q.front() << endl;

    return 0;
}