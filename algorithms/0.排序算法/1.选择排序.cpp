#include <iostream>
#include <vector>

using namespace std;

// 思想：遍历[0, n) n-1 个位置，找出[i, n)中最小的，将其和第i个元素进行交换
// 原地排序，空间复杂度: O(1)
// 时间复杂度: O(n^2)
// 不是稳定排序，如排序 [2, 2, 2, 1] 时会打乱2的顺序

void selectSort(vector<int>& nums) {
    int n = nums.size();
    // < sortedIndex 前面的已经排序
    int sortedIndex = 0;
    // ----- 对 nums 扫两遍 -----
    while(sortedIndex < n) { // 遍历 [0, n) 共 n 个位置
        int minIndex = sortedIndex;
        for (int i = sortedIndex; i < n; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i; // 找到最小元素的索引
            }
        }

        swap(nums[sortedIndex], nums[minIndex]);
        sortedIndex++; // 循环变量 +1
    }
}