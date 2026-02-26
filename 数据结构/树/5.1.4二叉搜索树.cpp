// 二叉搜索树BST：所有节点满足左小右大
// 即：所有节点的左子树上的所有节点都小于该节点，右子树的所有节点都大于该节点

// 二叉搜索树查找某元素理想时间复杂度是树的高度 - O(log N)

// 经典的二叉搜索树`TreeMap` / `TreeSet`
// `TreeMap` 的键是二叉搜索树，`TreeSet`是`TreeMap`的封装

#include <iostream>

// `TreeNode`结构
class treeNode {
public:
    int val;
    treeNode* left;
    treeNode* right;

    treeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};
// 用来实现`TreeMap`的`TreeNode`
template<typename K, typename V>
class TreeNode {
public:
    K key;
    V value;
    TreeNode<K, V>* left;
    TreeNode<K, V>* right;
    TreeNode(K key, V value) : key(key), value(value), left(nullptr), right(nullptr) {}
};

// 对于`TreeMap`等Map数据结构，都有增/改、查、删、是否包含key、返回键集合（`TreeMap`有序）
// `TreeMap`还提供：查找最大/最小键、查找大于等于/小于等于key的最大键、查找排名`k`的键、查找键`key`的排名、区间查找

// 可以通过再`TreeNode`增加一个`size`字段加快排序相关方法的实现

// 二叉搜索树的时间复杂度取决于平衡度，树高越接近`log N`效率越高
// 如果不平衡，极端情况下时间复杂度会退化到O(N)（顺序表）
