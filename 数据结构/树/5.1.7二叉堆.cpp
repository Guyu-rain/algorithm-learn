#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
// 二叉堆是特殊的二叉树：任意节点的值，都大于等于（小于等于）左右子树所有节点的值
// 当大于等于时，称之为大根堆；小于等于时，称之为小根堆

// 通过sink, swim（下沉、上浮）维护二叉堆的性质

// 用数组模拟二叉树：前提是二叉树必须是完全二叉树

template<typename T> 
class MyPriorityQueue {
private:
    // 堆数组 - 节点索引从 0 开始
    std::vector<T> heap;

    // 堆中元素的数量
    int size;

    // 元素比较器
    std::function<bool(const T&, const T&)> comparator;

    // 父节点的索引
    int parent(int node) {
        return (node - 1) / 2;
    }

    // 左子节点的索引
    int left(int node) {
        return node * 2 + 1;
    }

    // 右子节点的索引
    int right(int node) {
        return node * 2 + 2;
    }

    // 交换数组中的两个元素
    void swap(int i, int j) {
        std::swap(heap[i], heap[j]);
    }

    // 调整堆的大小
    void resize(int capacity) {
        if (capacity > size) {
            heap.resize(capacity);
        }
    }

    // 上浮操作，时间复杂度是树高 O(logN)
    void swim(int node) {
        while (node > 0 && comparator(heap[parent(node)], heap[node])) {
            swap(parent(node), node);
            node = parent(node);
        }
    }

    // 下沉操作，时间复杂度是树高 O(logN)
    void sink(int node) {
        
        while (left(node) < size || right(node) < size) {
            // 比较自己和左右子节点，看看谁最小
            int min = node;
            if (left(node) < size && comparator(heap[min], heap[left(node)])) {
                min = left(node);
            }
            if (right(node) < size && comparator(heap[min], heap[right(node)])) {
                min = right(node);
            }
            if (min == node) {
                break;
            }
            // 如果左右子结点中有比自己小的，交换
            swap(node, min);
            node = min;
        }
    }
public:
    MyPriorityQueue(int capacity, std::function<bool(const T&, const T&)> comparator)
        : heap(capacity), size(0), comparator(std::move(comparator)) {}

    // 返回堆的大小
    int getSize() const {
        return size;
    }

    // 判断堆空
    int isEmpty() const {
        return size == 0;
    } 

    // 查，返回堆顶元素，时间复杂度 O(1)
    const T& peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Priority queue underflow");
        }
        return heap[0];
    }

    // 增，向堆中插入一个元素，时间复杂度O(logN)
    void push(const T& x) {
        // 扩容
        if (size == heap.size()) { resize(2 * heap.size()); }
        // 将新元素追加到最后
        heap[size] = x;
        // 然后上浮到正确位置
        swim(size);
        size++;
    }

    // 删，删除堆顶元素，时间复杂度 O(logN)
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Priority queue underflow");
        }
        T res = heap[0]; // 待删元素
        // 将堆底元素放到堆顶
        swap(0, size - 1);
        size--;
        sink(0);
        // 缩容
        if (size > 0 && size == heap.size() / 4) {
            resize(heap.size() / 2);
        }
        return res;
    }
};

// 调试
int main() {
    // 使用lambda表达式来传递比较器
    // 小顶堆
    MyPriorityQueue<int> pq(3, [](const int& a, const int& b) { return a > b; });
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);
    pq.push(9);

    // 1 1 3 4 5 9
    while (!pq.isEmpty()) {
        std::cout << pq.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}