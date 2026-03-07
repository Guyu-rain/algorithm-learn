#include <iostream>
#include <vector>

using namespace std;

// 思想：每次使原数组之成为 h有序数组。然后减小 h。
// 每次排序都是插入排序

void shellSort(vector<int>& nums) {
    int n = nums.size();
    int h = 1;
    while (h < n / 3) { 
        h = 3 * h + 1; // 通项公式：h = (3^n - 1) / 2
    }

    while (h >= 1) { // h=1 就是插入排序，所以要包含 h=1
        // 使数组成为 h有序数组，每次排序都是插入排序
        int sortedIndex = h; // 从 h 开始，循环变量
        while (sortedIndex < n) {
            for (int i = sortedIndex; i >= h; i -= h) {
                if (nums[i] < nums[i - h]) {
                    swap(nums[i], nums[i - h]);
                } else {
                    break;
                }
            }
            sortedIndex++;
        }

        h = h / 3;
    }
}