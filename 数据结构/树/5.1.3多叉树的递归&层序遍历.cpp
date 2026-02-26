#include <iostream>
#include <vector>
#include <queue>
#include <list>

// 多叉树数据结构
class Node {
public:
    int val;
    std::vector<Node*> children;
};

// 森林 - 多个树
std::list<Node> forest; 
// 对所有树进行DFS/BFS遍历，即可遍历森林所有节点

// 1. 多叉树DFS
void traverse(Node* root) {
    if(root == nullptr) return;

    // 前序遍历
    for (Node* child : root->children) {
        traverse(child);
    }
    // 后续遍历
}

// 2. 多叉树层序遍历BFS
// 2.1 不记录深度
void levelOrderTraverse(Node* root) {
    if (root == nullptr) return;

    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* cur = q.front(); q.pop();
        // 访问cur节点

        for (Node* child : cur->children) {
            q.push(child);
        }
    }
}

// 2.2 记录深度
void levelOrderTraverse(Node* root) {
    if (root == nullptr) return; // 空树

    std::queue<Node*> q;
    q.push(root);

    int depth = 1;

    while(!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            Node* cur = q.front(); q.pop();
            // 访问`cur`，所有的`cur`都是在`depth`层

            // 将`cur`所有`children`加入`q`
            for (Node* child : cur->children) {
                q.push(child);
            }
        }
        depth++;
    }
}

// 2.3 带边权的写法
class State {
public:
    Node* node;
    int depth;

    State(Node* node, int depth) : node(node), depth(depth) {}
};

// 假设所有边权 = 1
void levelOrderTraverse(Node* root) {
    if (root == nullptr) return;

    std::queue<State> q;
    q.emplace(root, 1);
    
    while(!q.empty()) {
        int sz = q.size();

        for (int i = 0; i < sz; i++) {
            State cur = q.front(); q.pop();
            // 访问`cur`对应的节点`cur->node`，其累计边权为`cur->depth`
            
            for (Node* child : cur.node->children) {
                q.emplace(child, cur.depth + 1); // 假设所有的边权为1
            }
        }
    }
}
