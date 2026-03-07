#include <iostream>
#include <vector>
using namespace std;

// 思想：将需要排序的数值作为索引，count 记录 nums[i] 出现了多少次，通过 count[i] += count[i - 1] 得到 i 应该在数组的位置
// 空间复杂度：count[] -> O(max - min), sorted[] -> O(n); 一共 O(max - min + n) 
// 时间复杂度：需要遍历 nums, count 两个数组各一次，时间复杂度为 O(n + max - min)
// 非比较排序：不依赖 if (nums[i] > nums[j]) 这种比较，而比较排序的时间复杂度很难下 O(NlogN)
// 稳定性：在 sorted[count[nums[i] + offset] - 1] = nums[i] 时，通过倒序遍历 nums，此时是稳定的
// 注意：在计算元素位置时，依赖 nums[i] 的有序性，因此不能用 hashMap 存储

// 处理包含负值的情况
void sort(vector<int>& nums) {
    // 找到最大最小元素，计算偏移量和 count 数组大小
    int min = INT_MAX, max = INT_MIN;

    for (int num : nums) {
        min = std::min(min, num);
        max = std::max(max, num);
    }

    int offset = -min;
    vector<int> count(max - min + 1, 0);

    // 统计每个元素出现的次数
    for (int num : nums) {
        count[num + offset]++;
    }

    // 累加 count 数组，得到的是 nums[i] 在排序后的数组中的结束位置
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    // 根据每个元素排序后的索引位置，完成排序
    // 从后向前遍历 nums，保证排序的稳定性
    vector<int> sorted(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
        sorted[count[nums[i] + offset] - 1] = nums[i];
        count[nums[i] + offset]--;
    }
    
    // 复制回去
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = sorted[i];
    }
}