#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template<typename E>
class MyArrayList {
private:
    E* data; // 用来存储数据的数组
    int size; // 当前数组元素个数

    int cap; // 最大元素容量

    static const int INIT_CAP = 1; // 默认初始容量
public:
    MyArrayList() {
        this->data = new E[INIT_CAP];
        this->size = 0;
        this->cap = INIT_CAP;
    }

    MyArrayList(int initCapacity) {
        this->data = new E[initCapacity];
        this->size = 0;
        this->cap = initCapacity;
    }

    // 增
    void addLast(E e) {
        // 安全性检查: `data` 数组容量够不够
        if (size == cap) {
            resize(2 * cap);
        }
        // 在结尾插入元素
        data[size++] = e;
    }

    void add(int index, E e)
    {
        // 检查索引越界 - 插入位置
        checkPositionIndex(index);

        // 查看 data 容量是否够用
        if (size == cap) {
            resize(2 * cap);
        }

        // 迁移数据
        for (int i = size - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }

        // 插入元素
        data[index] = e;
        size++;
    }
    void addFirst(E e) {
        add(0, e);
    }

    // 删
    E removeLast() {
        if (size == 0) {
            throw std::out_of_range("NoSuchElementException");
        }
        // 当只用到`1/4`的空间时，可以缩容到`1/2`，节约空间
        if (size == cap / 4) {
            resize(cap / 2);
        }

        E deleteVal = data[size - 1];
        // 删除最后一个元素，同时避免内存泄露
        data[size - 1] = E(); // 将最后一个元素置为`null`
        size--;

        return deleteVal;
    }

    E remove(int index){
        // 检查索引越界
        checkElementIndex(index);

        // 可以缩容，节约空间
        if (size == cap / 4) {
            resize(cap / 2);
        }

        E deleteVal = data[index];

        // 迁移数据 data[index+1..] -> data[index..]
        for (int i = index + 1; i < size; i++) {
            data[i - 1] = data[i];
        }

        // 需要将最后一个位置置为null，避免内存泄露
        data[size - 1] = E();
        size--;

        return deleteVal;
    }

    E removeFirst() {
        return remove(0);
    }

    // 查
    E get(int index) {
        // 检查索引越界
        checkElementIndex(index);

        return data[index];
    }

    // 改
    E set(int index, E element) {
        // 检查索引越界
        checkElementIndex(index);
        // 修改数据
        E oldVal = data[index];
        data[index] = element;
        return oldVal;
    }

    // 工具方法
    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    // 将 data 的容量改为newCap
    void resize(int newCap) {
        E* temp = new E[newCap];

        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }

        delete[] data; // 释放内存

        data = temp;
        cap = newCap; // 更改容量
    }

    bool isElementIndex(int index) {
        return index >= 0 && index < size;
    }

    bool isPositionIndex(int index) {
        return index >= 0 && index <= size; // size的位置也是可以插入的
    }

    // 查 index 索引位置是否可以存在元素
    void checkElementIndex(int index) {
        if (!isElementIndex(index)) {
            throw std::out_of_range("Index out of bounds");
        }
    }

    // 查 index 位置是否可以插入元素
    void checkPositionIndex(int index) {
        if (!isPositionIndex(index)) {
            throw std::out_of_range("index out of boundes");
        }
    }

    void display() {
        std::cout << "size = " << size << " cap = " << cap << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    ~MyArrayList() {
        delete[] data;
    }
};

int main() {
    // 初始容量设置为 3
    MyArrayList<int> arr(3);

    // 添加 5 个元素
    for (int i = 1; i <= 5; i++) {
        arr.addLast(i);
    }

    arr.remove(3);
    arr.add(1, 9);
    arr.addFirst(100);
    int val = arr.removeLast();

    // 100 1 9 2 3
    for (int i = 0; i < arr.getSize(); i++) {
        std::cout << arr.get(i) << std::endl;
    }

    return 0;
}