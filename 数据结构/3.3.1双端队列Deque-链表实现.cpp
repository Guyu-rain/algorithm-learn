#include <iostream>
#include <list>

template<typename E>
class MyListDeque {
private:
    std::list<E> list;

public:
    void addFirst(E e) {
        list.push_front(e);
    }

    void addLast(E e) {
        list.push_back(e);
    }

    E removeFirst() {
        E firstElement = list.front();
        list.pop_front();
        return firstElement;
    }

    E removeLast() {
        E lastElement = list.back();
        list.pop_back();
        return lastElement;
    }

    E peekFirst() {
        return list.front();
    }

    E peekLast() {
        return list.back();
    }
};

int main() {
    MyListDeque<int> deque;
    deque.addFirst(1);
    deque.addFirst(2);
    deque.addLast(3);
    deque.addLast(4);

    std::cout << deque.removeFirst() << std::endl; // 2
    std::cout << deque.removeLast() << std::endl; // 4
    std::cout << deque.peekFirst() << std::endl; // 1
    std::cout << deque.peekLast() << std::endl; // 3
    return 0;
}