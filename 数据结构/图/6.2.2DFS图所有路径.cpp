#include <iostream>
#include <vector>
#include <list>

// onPath 数组：避免成环，如果是无环图不需要 onPath 数组
// 对于树，遍历所有节点和路径并没有本质区别
// 图两个节点直接可能有多条路径
const int N = 100; // 图节点个数

// 图节点，使用邻接表或邻接矩阵效果类似
class Vertex {
public:
    int id;
    std::vector<Vertex*> neighbors;
};

// onPath 和 path 记录当前递归路径上的节点
// onPath 类似于 visited 数组，避免成环（死循环）
std::vector<bool> onPath(N);
std::list<int> path;

void traverse(Vertex* src, Vertex* dest) {
    if (src == nullptr) { return; } // base case
    
    if (onPath[src->id]) { return; } // 防止死循环

    if (src->id == dest->id) { // 找到一条路径
        for (auto it = path.begin(); it != path.end(); it++) {
            std::cout << *it << "->"; 
        }
        std::cout << dest->id << std::endl;
        return;
    }

    // 前序位置
    onPath[src->id] = true;
    path.push_back(src->id);
    for (Vertex* v : src->neighbors) {
        traverse(v, dest);
    }
    // 后序位置
    // 一定要回溯 path 和 onPath 数组
    path.pop_back();
    onPath[src->id] = false;
}