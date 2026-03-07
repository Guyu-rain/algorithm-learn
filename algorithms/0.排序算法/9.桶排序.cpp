#include <vector>
using namespace std;
// 将原数组分入k个“桶”，然后进行插入排序
// 注意：每个桶中的任意元素满足：i < j, buckets[i][] < buckets[j][]
// 然后直顺序将 buckets[] 合并起来即可

// 空间复杂度: O(n + k)
// 均摊的时间复杂度：O(n + k)
// 排序时，使用插入排序 或 递归，稳定性与使用的排序方法有关，一般是稳定的

void bucketSort(vector<int>& nums, int bucketCount) {
    int min = INT_MAX, max = INT_MIN;
    for (int num : nums) {
        min = std::min(min, num);
        max = std::max(max, num);
    }

    // 类似计数排序
    int offset = -min;
    // 计算桶大小
    int bucketSize = (max - min) / bucketCount + 1;

    // 初始化桶
    vector<vector<int>> buckets(bucketCount, {});
    
    // 将元素分配到桶中
    for (int num : nums) {
        int index = (num + offset) / bucketSize;
        buckets[index].push_back(num);
    }

    // 对每个桶中的元素进行排序 - 插入排序
    for (int i = 0; i < bucketCount; i++) {
        insertSort(buckets[i]);
    }

    // 然后将桶直接合并即可
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int num : buckets[i]) {
            nums[index++] = num;
        }
    }
}

void insertSort(vector<int>& nums) {
    int bound = nums.size();
    int sortedIndex = 0;

    while(sortedIndex < bound) {
        for (int i = sortedIndex; i > 0; i--) {
            if (nums[i] < nums[i - 1]) {
                swap(nums[i], nums[i - 1]);
            } else {
                break;
            }
        }
        
        sortedIndex++;
    }
}

// 或者使用递归
