#include <iostream>

// 使用循环数组来实现 - CycleArray(2.3.1中实现)
template<typename E>
class MyArrayQueue {
private:
    CycleArray<E> arr;

public:
    MyArrayQueue() {
        arr = CycleArray<E>();
    }

    void push(E t) {
        arr.addLast(t);
    }

    E pop() {
        return arr.removeLast();
    }

    E peek() {
        return arr.getFirst();
    }

    int size() {
        return arr.size();
    }
};