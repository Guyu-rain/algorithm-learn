#include <stack>
#include <iostream>

using namespace std;

int main() {
    // 初始化一个空整型栈 s
    stack<int> s;

    // 向栈顶添加元素
    s.push(10);
    s.push(20);
    s.push(30);

    // 检查栈顶是否为空
    cout << s.empty() << endl;

    // 获取栈顶元素
    cout << s.top() << endl;

    // 删除栈顶元素
    s.pop();

    // 输出新的栈顶元素
    cout << s.top() << endl;

    return 0;
}