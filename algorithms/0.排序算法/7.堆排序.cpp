#include <queue>
#include <vector>
#include <iostream>

void _heapSort (std::vector<int>& nums) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    // Heapify - O(NlogN)
    for (int num : nums) {
        pq.push(num);
    }

    // 将元素取出 O(NlogN)
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = pq.top(); pq.pop();
    }
}

// 思想：使用 priority_queue，然后：
// 1. 原地建堆(Heapify)：将待排序数组变成一个二叉堆
// 2. 排序(Sort)：将元素不断从堆中取出，最终得到有序的结果

// 堆排序需要解决的是：不适用额外的辅助空间，在原数组上进行 sink, swim，在 O(NlogN)时间内完成排序
// 需要手写 sink, swim，然后
// 1. heapify： 对 nums[0..n-1] 每一个位置 swim(nums, i)，完成后，nums[]就是一个堆
// 2. sort: 从 n-1->0 每一个位置(记heapSize初始), 
// 2.1 swap(nums, 0, heapSize - 1)（也就是将堆顶元素换到num[heapSize - 1]）
// 2.2 维持 nums[0..heapSize-1] 仍然是一个堆，sink(nums, 0, heapSize)
// 可见，如果要升序，需要建立一个大根堆，下列函数默认实现大根堆

// heap 索引从 0 开始
void swim(std::vector<int>& heap, int node) {
    while (node > 0 && heap[node] > heap[(node - 1) / 2]) {
        std::swap(heap[node], heap[(node - 1) / 2]);
        node = (node - 1) / 2;
    }
}

void sink(std::vector<int>& heap, int node, int size){
    while (2 * node + 1 < size) { // 左右孩子至少有一个小于 size，不需要判断右孩子
        int max = node;
        // 选择最大孩子
        if (2 * node + 1 < size && heap[2 * node + 1] > heap[max]) { max = 2 * node + 1; }
        if (2 * node + 2 < size && heap[2 * node + 2] > heap[max]) { max = 2 * node + 2; }
        
        if (max == node) { break; }

        std::swap(heap[node], heap[max]);
        node = max;
    }
}

void heapSort(std::vector<int>& nums) {
    int size = nums.size();
    // Heapify - 模拟建堆，将数组从头到尾 swim 一次
    for (int i = 0; i < size / 2; i++) {
        swim(nums, i);
    }

    // Sort - 将nums[0]（排好序）swap 到最后，然后 sink nums[0]
    int heapSize = nums.size();
    while (heapSize > 0) {
        std::swap(nums[0], nums[heapSize - 1]);
        heapSize--;
        sink(nums, 0, heapSize);
    }
}

// 优化：优化建堆的过程
// 性质：二叉堆的子堆也是二叉堆，即小根堆的左右子树也是小根堆
// 而已知一个数组 nums, 其叶子节点是最自然的二叉堆，可以倒序建立二叉堆：从最后一个非叶子节点开始 sink，直到第一个节点
// 每一次sink，都能够让该部分子结构成为一个二叉堆

void heapSort(std::vector<int>& nums) {
    int size = nums.size();
    // Heapify - 模拟建堆
    // 画一个二叉堆，i 为 index，i == 0 (根节点)也需要 sink
    for (int i = size / 2 - 1; i >= 0; i--) {
        sink(nums, i, size); // 最后一个参数是 bound，因此一直是 size
    }

    // Sort - 将nums[0]（排好序）swap 到最后，然后 sink nums[0]
    int heapSize = nums.size();
    while (heapSize > 0) {
        std::swap(nums[0], nums[heapSize - 1]);
        heapSize--;
        sink(nums, 0, heapSize);
    }
}
