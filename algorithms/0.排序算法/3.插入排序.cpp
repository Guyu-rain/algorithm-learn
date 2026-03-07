#include <iostream>
#include <vector>

using namespace std;

// 思想：对选择排序的令一种优化
// nums[0, sortedIndex-1] 这一部分已经排序完成，可以将nums[sortedIndex]插入其中
// 具体而言，找到需要插入的位置后，将后面的元素统一向后移动
// 相同优化：通过从 sortedIndex 到插入位置的倒序交换来实现

// 插入排序：原数组约有序，效率越高，可以近似O(n)
// 时间复杂度：O(n^2)
// 原地排序，空间复杂度：O(1)

void insertSort(vector<int>& nums) {
    int n = nums.size();
    int sortedIndex = 0;

    while(sortedIndex < n) {
        for (int i = sortedIndex; i > 0; i--) {
            if (nums[i] < nums[i - 1]){
                swap(nums[i], nums[i - 1]);
            } else {
                break; // 直接 break - 原数组越有序，效率越高
            }
        }

        sortedIndex++;
    }
}