#include <iostream>
#include <list>

template<typename E>
class MyLinkedStack {
private:
    std::list<E> list;

public:
    void push(const E &e) {
        list.push_back(e);
    }

    E pop() {
        E value = list.back();
        list.pop_back();
        return value;
    }

    E peek() const {
        return list.front();
    }

    int size() const {
        return list.size();
    }

};

int main() {
    MyLinkedStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    while (stack.size() > 0) {
        std::cout << stack.pop() << std::endl;
    }
    return 0;
}