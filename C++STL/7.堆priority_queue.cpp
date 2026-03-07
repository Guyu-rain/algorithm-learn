#include <queue>
#include <vector>

// 二叉堆初始化，不接受开一个初始空间；
// 不接受随机访问
std::priority_queue<int> pq;

// 一个很别扭的初始化方式
std::vector<int> v{1, 2, 3, 4, 5};
std::priority_queue<int> pq(v.begin(), v.end());

// 小根堆
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

// 支持直接对 pair 建堆，会先对 p.first 进行比较，然后对 p.second 进行比较
std::priority_queue<std::pair<int, int>, 
                    std::vector<std::pair<int, int>>, 
                    std::greater<std::pair<int, int>>> pq;

// 对结构体等建立小根堆堆
struct node {
    int val;
    node* next;

    node(int val, node* next) : val(val), next(next) {}
};

// 方法1：写比较器
struct Cmp {
    bool operator() (node* a, node* b) const {
        return a->val > b->val; // 如果前面的比后面的大 -> true -> 交换 -> 小根堆
    }
};
std::priority_queue<node*, std::vector<node*>, Cmp> pq;

// 方法2：lambda
auto cmp = [](node* a, node* b) {
    return a->val > b->val;
}; 
// 定义一个 priority_queue pq, 其比较器类型是 "cmp" 这个 lambda 的类型，并用cmp初始化它

std::priority_queue<node*, std::vector<node*>, decltype(cmp)> pq(cmp);