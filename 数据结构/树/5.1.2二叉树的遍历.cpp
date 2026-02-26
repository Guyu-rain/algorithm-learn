#include <iostream>
#include <stack>
#include <queue>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// DFS - 深度优先遍历 - {前序, 中序, 后序}
// 1 - 递归写法
// 遍历节点的顺序永远是一样的：先进入`root`节点，然后先遍历左子树，直到左子树空，返回，遍历右子树
// 前中后序的区别，在于什么时候处理`root`节点
// 前序遍历 - 进入时
// 中序遍历 - 左子树遍历完成后
// 后续遍历 - 左右子树都遍历完成后
void traverse(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // 前序位置
    traverse(root->left); // 先遍历所有左子树节点
    // 中序位置
    traverse(root->right); // 直到左子树为空，才开始遍历右子树节点
    // 后序位置
};

// 二叉搜索树(BST)的中序遍历结果是有序的

// 2 - 迭代写法
// 显式维护一个递归栈
// 前序遍历 / 中序遍历
void traversal_1(TreeNode* root) {
    std::stack<TreeNode*> stk;
    TreeNode* node = root;
    while(!stk.empty() || node != nullptr) {
        while(node != nullptr) {
            // 前序遍历
            stk.emplace(node); // 注意是emplace，构造一个新的树节点，而不是使用现有的树节点
            node = node->left; // 一路向左遍历到头
        }
        // 左子树为空
        node = stk.top(); stk.pop();
        // 中序遍历
        node = node->right; // 去右子树
    }
}

void traversal_2(TreeNode* root) {
    std::stack<TreeNode*> stk;
    TreeNode* node = root;
    TreeNode* prev = nullptr;

    while(!stk.empty() || node != nullptr) {
        while(node != nullptr) {
            stk.emplace(node);
            node = node->left;
        }
        node = stk.top(); stk.pop();
        if (node->right == nullptr || node->right == prev) { // 右子树空 || 从右子树返回
            // 后序遍历
            prev = node;
            node = nullptr;
        } else { // 右子树还没遍历完 - 需要压回 + 去到右子树
            stk.push(node);
            node = node->right;
        }
    }
}

// BFS - 层序遍历
// 1. 直接BFS，无法知道是第几层
void levelOrderTraverse(TreeNode* root) {
    if (root == nullptr) return;

    std::queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
        TreeNode* cur = q.front(); q.pop();
        // 访问`cur`节点
        std::cout << cur->val << std::endl;
        
        // 将`cur`左右子节点加入队列
        if (cur->left != nullptr) q.push(cur->left);
        if (cur->left != nullptr) q.push(cur->right);
    }
}

// 2. 知道层数的遍历方式
void levelOrderTraverse(TreeNode* root) {
    if (root == nullptr) return; // 空树返回

    std::queue<TreeNode*> q;
    q.push(root);

    int depth = 1;

    while(!q.empty()) {
        int sz = q.size();
        while(sz--) { // 循环`size`次
            TreeNode* cur = q.front(); q.pop();
            // 访问`cur`节点，`depth`就是其层数
            
            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
        depth++;
    }
}

// 如果需要知道当前节点是树的第几个节点，while(sz--)应换成for()循环
// for (int i = 1; i <= sz; i++) { ... }

// 3. 带有边权的BFS
struct state {
    TreeNode* node;
    int depth;

    state(TreeNode* node, int depth) : node(node), depth(depth) {}
};

void levelOrderTraverse(TreeNode* root) {
    if (root == nullptr) return;

    std::queue<state> q;
    q.push(state(root, 1));
    // 假设所有边权为1
    
    while(!q.empty()) {
        int sz = q.size();
        for (int i = 1; i <= sz; i++) {
            state cur = q.front(); q.pop();
            // 访问当前节点`cur`

            if (cur.node->left != nullptr) q.push({cur.node->left, cur.depth + 1});
            if (cur.node->right != nullptr) q.push({cur.node->right, cur.depth + 1});
        }
    }
}