#include <list> // 使用双向链表实现队列
#include <iostream>

/*
    队列API:
    push()
    pop()
    peek() - 查看对头
    size() - 返回队列中元素
*/

// 用双向链表实现
template<typename E>
class MyLinkedQueue {
    private:
    std::list<E> list;

public:
    void push(const E &e) {
        list.push_back(e);
    }
    
    E pop() {
        E front = list.front();
        list.pop_front();
        return front;
    }

    E peek() {
        return list.front();
    }

    int size() {
        return list.size();
    }
};

int main() {
    MyLinkedQueue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    std::cout << queue.peek() << std::endl; // 1
    std::cout << queue.pop() << std::endl; // 1
    std::cout << queue.pop() << std::endl; // 2
    std::cout << queue.peek() << std::endl; // 3

    return 0;
}