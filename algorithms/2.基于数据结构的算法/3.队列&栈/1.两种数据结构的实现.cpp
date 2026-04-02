/*
    两种数据结构都是**受限**的线性结构。
    - 队列：先进先出
    - 栈：先进后出
    *栈更受限制
*/
#include <iostream>
#include <stack>

// 用栈实现队列
// 如果要用栈实现队列，用一个更受限的数据结构实现一个稍自由的数据结构
// 实际上挺抽象的，要用到两个栈
// s1 模拟队尾，s1模拟队头
class Queue {
private:
    // 栈 s1 用来处理队尾 - 入队
    // 栈 s2 用来处理队头 - 查看队头 / 出队
    std::stack<int> s1, s2;
public:
    // 实现如下的接口
    Queue() {
        // 构造函数，初始化了两个栈
    }
    // 添加元素到队尾
    void push(int x) {
        s1.push(x);
    }

    // 删除队头元素并返回
    int pop() {
        // 将 s1 全部压入 s2
        peek();
        // 弹出 s2 栈顶的元素
        int topElement = s2.top();
        s2.pop();
        return topElement;
    }
    // 返回队头元素
    int peek() {
        // 只有s2中为空，才需要从s1向s2压入元素 
        if (s2.empty()) {
            // 将 s1 元素压入 s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

// 用队列实现栈
// 用一个队列即可
class Stack {
    std::queue<int> q;
    int top_elem = 0;

public:
    // 添加元素到栈顶
    void push(int x) {
        // x 是队列的队尾，是栈的栈顶
        q.push(x);
        top_elem = x;
    }
    
    int top() {
        return top_elem;
    }

    bool empty() {
        return q.empty();
    }
    // 删除栈顶的元素并返回
    int pop() {
        // 栈顶对应队尾
        // 需要不停将队头元素出队放到队尾
        // 直到队尾变成队头，此时真正 pop，然后返回这个值
        // 需要注意：top_elem 需要被正确更新为队尾元素
        int size = q.size();
        while (size > 2) {
            q.push(q.front()); q.pop();
            size--;
        }
        // 这个元素是队尾
        top_elem = q.front();
        q.push(q.front()); q.pop();
        // 记录队头元素
        int target = q.front();
        q.pop();
        return target;
    }
};