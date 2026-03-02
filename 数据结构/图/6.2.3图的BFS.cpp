#include <vector>
#include <queue>
#include <iostream>

// 图 BFS 就是比多叉树多了一个 visited 数组，防止成环（重复遍历）
// 每次 push 前检查 visited[id] == false，push 后将 visited[id] = true
const int N = 1e2 + 10; // 数据规模

// 抽象一个图节点
class Vertex {
public:
    int id;
    std::vector<Vertex*> neighbors;
};

// 1. 不记录层数
// 从节点 s 开始BFS
void bfs1(Vertex* s) {
    std::queue<Vertex*> q;
    std::vector<bool> visited(N, false);
    q.push(s);
    visited[s->id] = true;

    while(!q.empty()) {
        Vertex* cur = q.front(); q.pop();
        for (Vertex* u : cur->neighbors) {
            if (visited[u->id]) { continue; } // ！注意，需要判断是否已经访问！
            q.push(u);
            visited[u->id] = true;
        }
    }
}

// 2. 记录步数
void bfs2(Vertex* s) {
    std::queue<Vertex*> q;
    std::vector<bool> visited(N, false);
    q.push(s); visited[s->id] = true;
    // 记录从 s 开始走到当前节点的步数
    int step = 0;
    while(!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            Vertex* cur = q.front(); q.pop();
            // 访问 v 节点
            std::cout << "visit " << cur->id << " at step " << step << std::endl;
            for (Vertex* v : cur->neighbors) {
                q.push(v);
            }
        }
        step++;
    }
}

// 3. 带边权的写法
// 每个节点也需要维护一个 State，这里用 step 代替边权
class State {
public:
    Vertex* node; // 当前 id
    int step;

    State(Vertex* node, int step) : node(node), step(step) {}
};

void bfs3(Vertex* s) {
    std::vector<bool> visited(N, false); 
    std::queue<State> q;

    q.emplace(s, 0);
    visited[s->id] = true;

    while(!q.empty()) {
        State state = q.front(); q.pop();
        Vertex* cur = state.node;
        int step = state.step;
        std::cout << "visit " << cur->id << " with step " << step << std::endl;

        for (Vertex* v : cur->neighbors) {
            if (visited[v->id]) { continue; }
            q.emplace(v, step + 1);
            visited[v->id] = true;
        }
    }
}