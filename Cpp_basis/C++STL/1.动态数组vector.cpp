#include <vector>
#include <iostream>

int n = 10, m = 8;

// ----- 初始化 -----
std::vector<int> nums;
std::vector<int> nums(n); // 初始化一个大小为`n`的数组`nums`，其中的数都默认为 0

std::vector<int> nums{1, 3, 5}; // 带有初始值的 - 优先使用
std::vector<int> nums = {1, 3, 5}; // 同上
std::vector<int> nums = std::vector<int>{1, 3, 5}; // 同上

std::vector<int> nums(n, 2); // 初始化一个大小为`n`的数组`nums`，值全为 2

std::vector<std::vector<int>> dp; // 初始化一个二维数组`dp`

// 初始化一个大小为 m * n 的bool数组dp，所有值初始化为true
std::vector<std::vector<bool>> dp(m, std::vector<bool>(n, true));

// ----- vector的常见操作 -----
using namespace std;

int main() {
    vector<int> nums(n);

    // 检查数组是否为空
    cout << nums.empty() << endl; // 输出 0 (false)

    // 获取数组大小
    cout << nums.size() << endl; // 输出 10 - 注意是10，而不是0

    // 两个尾部操作 - O(1)
    // 1. 增
    nums.push_back(20);
    cout << nums.size() << endl; // 输出 11

    // 2. 删
    nums.pop_back(); // 没有返回值
    cout << nums.size() << endl; // 输出 10

    // `[]`索引 - O(1)
    nums[0] = 11;
    cout << nums[0] << endl; // 输出 11

    // 插入 - O(N)
    nums.insert(nums.begin() + 3, 99); // 使用`begin()迭代器` + `offset`

    // 删除 - O(N)
    nums.erase(nums.begin() + 2); // 同上

    // 交换
    swap(nums[0], nums[1]);

    // 遍历
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}