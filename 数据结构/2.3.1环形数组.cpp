#include <iostream>
#include <stdexcept>
#include <vector>
#include <ostream>

// 核心公式：index = (index + arrsize + offset) % arrsize, 当offset为正时，不需要+arrsize
// 环形数组左闭右开[start, end)
template<typename T>
class CycleArray {
    std::vector<T> arr; // 使用`vector`作为数组
    int start;
    int end;
    int count;

    // 自动缩扩容辅助函数
    void resize(int newSize) {
        std::vector<T> newArr(newSize);
        for (int i = 0; i < count; ++i) {
            newArr[i] = arr[(start + i) % arr.size()];
        }
        arr = std::move(newArr);
        // 重置 start 和 end 指针
        start = 0;
        end = count;
    }

public:
    CycleArray() : CycleArray(1) {}

    explicit CycleArray(int size) 
        : arr(size), start(0), end(0), count(0) {}
    
    // 数组头部添加元素，时间复杂度为 O(1)
    void addFirst(const T &val) {
        // 数组满时，扩容为原来的两倍
        if (isFull()) {
            resize(arr.size() * 2);
        }
        start = (start - 1 + arr.size()) % arr.size();
        arr[start] = val;
        count++;
    }

    // 删除数组头部元素，时间复杂度 O(1)
    void removeFirst() {
        if (isEmpty()) {
            throw std::runtime_error("Array is Empty");
        }
        arr[start] = T();
        start = (start + 1) % arr.size();
        count--;
        // 缩容
        if (count > 0 && count == arr.size() / 4) {
            resize(arr.size() / 2);
        }
    }

    // 在数组尾部添加元素，时间复杂度O(1)
    void addLast(const T &val) {
        if (isFull()) {
            resize(arr.size() * 2);
        }

        arr[end] = val;
        end = (end + 1) % arr.size();
        count++;
    }

    // 删除数组尾部元素，时间复杂度 O(1)
    void removeLast() {
        if(isEmpty()) {
            throw std::runtime_error("Array is Empty");
        }
        end = (end - 1 + arr.size()) % arr.size();
        arr[end] = T();
        count--;
        // 缩容
        if (count > 0 && count == arr.size() / 4) {
            resize(arr.size() / 2);
        }
    }

    // 获取数组头部元素，时间复杂度 O(1)
    T getFirst() const {
        if (isEmpty) {
            throw std::runtime_error("Array is Empty");
        }
        return arr[start];
    }

    // 获取数组尾元素，时间复杂度O(1)
    T getLast() const {
        if (isEmpty()) {
            throw std::runtime_error("Array is empty");
        }
        // end 是开区间，指向的是下一个元素的位置
        return arr[(end - 1 + arr.size()) % arr.size()];
    }

    bool isFull() const {
        return count == arr.size();
    }

    int size() const {
        return count;
    }
    
    bool isEmpty() const {
        return count == 0;
    }
};

int main() {


    return 0;
}