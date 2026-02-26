#include <unordered_map>
#include <vector> 

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 结构体：
struct TNode {
    int val;
    TNode* left;
    TNode* right;
    TNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 使用hash表来定义一棵树，是邻接表的表示方法
// key -> {孩子节点}
std::unordered_map<int, std::vector<int>> tree;
tree[1] = {2, 3}; // 先后顺序表示左右节点
tree[2] = {4};
tree[3] = {5, 6};