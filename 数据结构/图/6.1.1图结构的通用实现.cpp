#include <vector>

// 图节点的逻辑结构
class Vertex {
public:
    int id;
    std::vector<Vertex*> neighbors;
};

// 下面的实现为有向图，无向图等价于双向有向图
// 邻接表和邻接矩阵实现图结构
// 1. 邻接表 - 存储稀疏图
// graph[x] 存储 x 的所有邻居节点
std::vector<std::vector<int>> graph;

// 2. 邻接矩阵
// matrix[x][y] 记录 x 是否有一条指向 y 的边
std::vector<std::vector<bool>> matrix;

// 如果图节点不是 int 类型，用一个 unordered_map<int, ...> 将节点与 id 映射

// 加权图的实现
// 1. 邻接表
struct Edge {
    int to;
    int weight;
};

std::vector<std::vector<Edge>> weightedGraph;

// 2. 邻接矩阵
// weightedMatrix[x][y] 表示边权
std::vector<std::vector<int>> weightedMatrix;

/// ---------------------------------
// ----- 竞赛中常见的定义：邻接表 -----
// 无权图
const int N = 2e5 + 10;
std::vector<int> adj[N];

// 带权图
std::vector<std::pair<int, int>> weighted_adj[N]; // (to, weight)
// 或用结构体
struct Edge {
    int to, w;
};
std::vector<Edge> weighted_adj[N];

// 然后一般会搭配一个 visited[] 数组
bool visited[N];

// ----- 如果需要O(1)访问边，用邻接矩阵 -----
int g[N][N];
// 或
std::vector<std::vector<int>> g(N, std::vector<int>(N));

// ----- 极限优化：链式前向星 -----
const int n = 1e5 + 10, m = 2e5 + 10;
int head[n], nxt[m], to[m], idx;
void add(int u, int v) {
    to[idx] = v;
    nxt[idx] = head[u];
    head[u] = idx++;
}

int main() {
    int u = 1, v = 2;

    adj[u].push_back(v);
    adj[v].push_back(u); // 无向图

    return 0;
}

