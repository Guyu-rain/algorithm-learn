#include <iostream>
#include <vector>

using namespace std;

// 过程：选择一个 pivot，将数组分成两部分
// 将所有比 pivot 小的放在 pivot 左边，比 pivot 大的放在 pivot 右边 —— 实际上就是将 pivot 排好序
// 递归排序左右两部分 - 二叉树的 DFS

// 有两个需要额外解决的问题
// 1. pivot 的选择需要随机
// 2. 初始顺序需要随机，尽量使树高为平衡二叉树；
// 否则算法最差可能退化到 O(N^2)

// 时间复杂度：O(NlogN)
// 原地排序，空间复杂度：O(logN) - 来自递归调用栈
// 是不稳定排序

class QuickSort {
public:
    // 使用 static 关键字确保无需实例化 QuickSort 即可调用
    static void sort(vector<int>& nums) {
        // 为了避免极端情况，先随机打乱
        shuffle(nums); 
        // 排序整个数组（原地修改）
        sort(nums, 0, nums.size() - 1); // 二叉树的遍历
    }
private:
    static void sort(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) { return; }
        // 对 nums[lo..hi] 进行切分
        // 使 nums[lo..p-1] <= nums[p] < nums[p+1..hi]
        int p = partition(nums, lo, hi);
        
        sort(nums, lo, p - 1);
        sort(nums, p + 1, hi);
    }

    // 对 nums[lo..hi] 进行切分
    static int partition(vector<int>& nums, int lo, int hi) {
        int pivot = nums[lo];
        // 定义 i, j 使 nums[lo..hi] 满足：
        // [lo, i) <= pivot; (j, hi] > pivot
        int i = lo + 1, j = hi;
        
        while (i <= j) {
            while (i < hi && nums[i] <= pivot) { i++; }
            while (j > lo && nums[j] > pivot) { j--; }
            // 到这里，能保证[lo, i) <= pivot; (j, hi] > pivot
            // 换言之，如果 i, j 如果没有到边界，此时有：
            // nums[i] > pivot, nums[j] <= pivot

            // 所以应该交换这两个位置
            if (i >= j) { break; }
            swap (nums[i], nums[j]);
            // 此时，[lo, i] <= pivot && [j, hi] > pivot
        }
        // 此时，满足了[lo, i) <= pivot; (j, hi] > pivot
        // 特别的，j <= pivot，不会超出范围（pivot 在 lo，最多和自己交换）
        // 将 pivot 放在合适的位置
        swap(nums[lo], nums[j]);
        return j;
    }

    static void shuffle(vector<int>& nums) {
        srand((unsigned) time(NULL));
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int r = i + rand()%(n-i);
            swap(nums[i], nums[r]);
        }
    }
};