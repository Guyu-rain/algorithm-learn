#include <iostream>
#include <vector>

using namespace std;

// 深度优先搜索
// visited 数组：防止成环，如果说明是无环图，则不需要 visited 数组
// 与多叉树完全相同，只是多了 visited 数组防止重复遍历 / 死循环
// 时间复杂度 O(E + V)

// 图结构
class Vertex {
public:
    int id;
    std::vector<Vertex*> neighbors;
}; // 图节点

void traverse(Vertex* s, std::vector<bool> visited) {
    if (s == nullptr) { return; } // 递归出口

    if (visited[s->id]) { return; } // 防止死循环

    // 前序位置
    visited[s->id] = true;
    cout << "visit " << s->id << endl; // 遍历的位置
    for (Vertex* v : s->neighbors) {
        traverse(v, visited);
    }
    // 后续位置
}

// 对邻接表、邻接矩阵的遍历类似

// 遍历所有边 - 二维 visited 数组
class Vertex {
public:
    int id;
    std::vector<Vertex*> neighbors;

    Vertex(int i = 0) : id(i) {}
};

// 遍历图的边
// 需要一个二维 visited 记录被遍历过的边，visited[u][v] 表示边 u->v 已经被遍历过
// 注意：一条边由两个节点组成，因此需要将前序位置的代码放在 for 循环的内部
void traverseEdges(Vertex* s, std::vector<std::vector<bool>>& visited) {
    // base case, 递归出口
    if (s == nullptr) { return; }
    // 避免死循环
    for (Vertex* v : s->neighbors) {
        // 如果已经访问，直接 continue
        if (visited[s->id][v->id]) {
            continue;
        }
        // 标记并访问边
        visited[s->id][v->id] = true;
        cout << "visit edge: " << s->id << " -> " << v->id << endl;
        traverseEdges(v, visited);
    }
}