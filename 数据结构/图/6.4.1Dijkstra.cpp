// Dijkstra算法本质是: BFS + 贪心
// 如果图中有负权重边，会让贪心思想失效

// Dijkstra与标准BFS区别只有两个：
// 1. Dijkstra使用priority_queue，让距离起点更近的节点先出队（贪心）
// 2. Dijkstra使用distTo数组，确保算法不会陷入死循环（代替visited），同时记录起点到其他节点的最短路径

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

// 带权图
struct Edge {
    int to;
    long long w;
};
vector<Edge> g[N];
vector<int> distTo(N, INT_MAX);

void dijkstra(int s) {
    // 如果有必要，进行初始化 dist = {INF}
    // (距离，节点)
    priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>
    > pq;

    distTo[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        
        // 类似 visited 数组，需要去掉较差的距离
        // 如果当前的 distTo[u] 比 pq 中的 d 更好，则这个路径不可能出现最短路径，直接掉过
        if (distTo[u] < d) { continue; }

        for (auto e : g[u]) {
            int v = e.to;
            int w = e.w;

            if (distTo[v] > distTo[u] + w) {
                distTo[v] = distTo[u] + w;
                pq.push({distTo[v], v});
            }
        }
    }
    // 如果要 return，return distTo;
}