#include <iostream>
#include <vector>

using namespace std;

// 将第 k 大，转换成第 num.size() - k 小（Index 从 0 开始）
// 思想：快排中，使用 pivot 将数组分成两部分，假设 pivot 位于第 p 位若：
// 1. p < k，则要找的数在 (p, hi]
// 2. p > k，则要找的数在 [lo, p)
// 3. p == k，return

// 时间复杂度：最好情况O(N) - 能一直实现折半查找，

class QuickSelect {
public:
    int quickSelect(vector<int>& nums, int k) {
        // 首先打乱数组
        shuffle(nums);
        // 开始找 nums.size() - k 位置的元素
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) { //
            int p = partition(nums, lo, hi);
            if (p < k) {
                lo = p + 1;
            } else if (p > k) {
                hi = p - 1;
            } else {
                return nums[p];
            }
        }
        return -1;
    }
private:
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
