#include <iostream>
#include <vector>

using namespace std;

// 思想：让冒泡排序具有稳定性；
// 冒泡排序不稳定是因为直接交换了 sortedIndex 和 minIndex
// 模仿顺序表插入元素，将 minIndex 移动到 sortedIndex 之后，将 [sortedIndex+1, n) 的元素向后移动一个
// 为了更快一步，可以从后向前扫描，如果相邻两个元素后者 < 前者，则 swap。这样也保证了稳定性
// 同时：如果一次扫描中没有 swap，说明此时已经排序完成！直接结束排序

void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    int sortedIndex = 0; // 循环变量，每次从 (n-1) -> sortedIndex
    while(sortedIndex < n) { // 循环 n 次
        bool swapped = false;
        for (int i = n - 1; i > sortedIndex; i--) {
            if (nums[i] < nums[i - 1]) { // 保证稳定性，使用 <
                swap(nums[i], nums[i - 1]);
                swapped = true;
            }
        }

        if (!swapped) { // 没交换，则：
            break;
        }
        sortedIndex++; // while 循环标准操作
    }
}