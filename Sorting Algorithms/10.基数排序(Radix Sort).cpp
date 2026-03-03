
// 思想：先按照个位数排序 -> 十位数 -> ...
// 关键：
// 1. 每一步都是稳定排序，最好的稳定排序是计数排序（通过倒序存储 sorted 函数来实现）
// 2. 处理负数：(1) 统一添加 offset (2) 正数、负数分开处理
// 3. 必须从低位到高位LSD(Least Significant Digit First)，MSD主要场景是字典序排列，实现需要用到递归，与LSD有很大不同

// 复杂度：十进制时，基数排序的时间复杂度为 O(n + max - min) = O(n + 10) = O(n)
// 时间复杂度：O(mn)
// 空间复杂度：O(n)

// LSD 代码的实现
// 正整数 num 获得第 k 位数字（从低位到高位为0, 1, 2,...），使用公式 (num / 10 ** k) % 10
// 这个公式很健壮，num 的总位数小于 k，则上式 == 0

#include <vector>
using namespace std;

// 基数排序
void radixSortLSD(vector<int>& nums) {
    int min = INT_MAX;
    for (int num : nums) {
        min = std::min(min, num);
    }

    // 用偏移量处理负数
    int offset = -min;
    for (int i = 0; i < nums.size(); i++) {
        nums[i] += offset;
    }

    int max = INT_MIN;
    for (int num : nums) {
        max = std::max(max, num);
    }

    // 计算最大元素的位数
    int maxLen = 0;
    while (max > 0) {
        max /= 10;
        maxLen++;
    }

    // 从低位到高位，一次对每一位进行计数排序
    for (int k = 0; k < maxLen; k++) {
        countSort(nums, k);
    }

    // 将所有元素转化为原来的值
    for (int i = 0; i < nums.size(); i++) {
        nums[i] -= offset;
    }
}

// 基数排序使用的计数排序算法函数
// 已经确保 nums 中的元素都是非负数
// k 是当前需要排序的位数
void countSort(vector<int>& nums, int k) {
    // 基数排序中每一位十进制数的取值范围是 0~9
    vector<int> count(10, 0);

    // 对每个元素的第 k 位进行计数
    for (int num : nums) {
        int digit = (num / static_cast<int>(pow(10, k))) % 10;
        count[digit]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    // 按照第 k 位的值对元素进行排序
    vector<int> sorted(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
        int digit = (nums[i] / static_cast<int>(pow(10, k))) % 10;
        sorted[count[digit] - 1] = nums[i];
        count[digit]--;
    }

    // 把排序结果复制回原数组
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = sorted[i];
    }
}