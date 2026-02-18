#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// 引入虚拟头尾节点，用来处理空链表的情况 - 虚拟节点对外透明
template<typename E>
class MyLinkedList {
    struct Node {
        E val;
        Node* next;
        Node* prev;
        
        Node(E value) : val(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() {
        head = new Node(E());
        tail = new Node(E());
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    ~MyLinkedList() {
        while (size > 0) {
            removeFirst();
        }
        delete head;
        delete tail;
    }

    // ***** 增 *****
    void addLast(E e) {
        Node* x = new Node(e);
        // 更新`新节点x`的指针
        x->next = tail;
        x->prev = tail->prev;
        // 更新`新节点x`前后两个节点指向`x`的指针
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }

    void addFirst(E e) {
        Node* x = new Node(e);
        x->next = head->next;
        x->prev = head;
        head->next->prev = x;
        head->next = x;
        size++;
    }

    void add(int index, E element) {
        checkPositionIndex(index);
        if (index == size) { // 特判是否是尾插
            addLast(element);
            return;
        }
        
        Node* p = getNode(index);
        Node *x = new Node(element);

        x->next = p;
        x->prev = p->prev;

        p->prev->next = x;
        p->prev = x;

        size++;
    }

    // ***** 删 *****
    E removeFirst() {
        if (size < 1) {
            throw std::out_of_range("No elements to remove");
        }
        // head <-> x(ready to remove)
        Node* x = head->next;
        head->next = x->next;
        x->next->prev = head;

        E val = x->val;
        delete x;

        size--;
        return val;
    }

    E removeLast() {
        if (size < 1) {
            throw std::out_of_range("No elements to remove");
        }
        // ... <-> x(ready to remove) <-> tail
        Node* x = tail->prev;
        tail->prev = x->prev;
        x->prev->next = tail;

        E val = x.val;
        delete x;

        size--;
        return val;
    }

    E remove(int index) {
        checkElementIndex(index);
        
        Node* x = getNode(index);
        x->next->prev = x->prev;
        x->prev->next = x->next;

        E val = x->val;
        x->prev = x->next = nullptr;
        delete x;

        size--;
        return val;
    }
    
    // ***** 查 *****
    E get(int index) {
        checkElementIndex(index);
        Node* p = getNode(index);

        return p->val;
    }
    
    E getFirst() {
        if (size < 1) {
            throw std::out_of_range("No elements in the list");
        }

        return head->next->val;
    }

    E getLast() {
        if (size < 1) {
            throw std::out_of_range("No elements in the list");
        }

        return tail->prev->val;
    }

    // ***** 改 *****
    E set(int index, E val) {
        checkElementIndex(index);

        Node* p = getNode(index);

        E oldVal = p->val;
        p->val = val;
        return oldVal;
    }

    // ***** 工具函数 *****
    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void display() {
        std::cout << "size = " << size << std::endl;
        for (Node* p = head->next; p != tail; p = p->next) {
            std::cout << p->val << " <-> ";
        }
        std::cout << "nullptr" << std::endl;
        std::cout << std::endl;
    }

private: // 隐藏`head, tail`
    Node* getNode(int index) {
        Node* p = head->next;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        return p;
    }

    bool isElementIndex(int index) const {
        return index >= 0 && index < size;
    }

    bool isPositionIndex(int index) const {
        return index >= 0 && index <= size;
    }

    // 检查index索引位置是否可以存在元素
    void checkElementIndex(int index) const {
        if (!isElementIndex(index))
        throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
    }

    // 检查 index 索引是否可以添加元素
    void checkPositionIndex(int index) const {
        if(!isPositionIndex(index))
            throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
    }
};

int main() {
    MyLinkedList<int> list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addFirst(0);
    list.add(2, 100);

    list.display();
    // size = 5
    // 0 <-> 1 <-> 100 <-> 2 <-> 3 <-> null
    return 0;
}