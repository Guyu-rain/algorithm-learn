#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class WeightedDigraph {
public:
    struct Edge {
        int to;
        int weight;
        
        Edge(int to, int weight) {
            this->to = to;
            this->weight = weight;
        }
    };

private:
    // 邻接表，graph[v] 存储节点 v 的所有邻居节点和权重
    vector<vector<Edge>> graph;

public:
    WeightedDigraph(int n) {
        graph = vector<vector<Edge>>(n); // 初始化一个邻接表
    }

    // 增，添加一条带权重的边，复杂度 O(1)
    void addEdge(int from, int to, int weight) {
        graph[from].emplace_back(to, weight);
    }

    // 删，删除一条有向边，复杂度 O(v)
    void removeEdge(int from, int to) {
        for (auto it = graph[from].begin(); it != graph[from].end(); ++it) {
            if (it->to == to) {
                graph[from].erase(it);
                break;
            }
        }
    }

    // 查，判断是否有 from -> to 的边，复杂度O(V)
    bool hasEdge(int from, int to) {
        for (const auto& e : graph[from]) {
            if (e.to == to) {
                return true;
            } 
        }
        return false;
    }

    // 查，返回一条边的权重，复杂度 O(V)
    int weight(int from, int to) {
        for (const auto& e : graph[from]) {
            if (e.to == to) {
                return e.weight;
            }
        }
        throw invalid_argument("No such edge");
    }

    // 查，返回某个节点的所有邻居节点，复杂度 O(1)
    const vector<Edge>& neighbors(int v) {
        // 省去对 v 的检查
        return graph[v];
    }
};

// 调试
int main() {
    WeightedDigraph graph(3);
    graph.addEdge(0, 1, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 0, 3);
    graph.addEdge(2, 1, 4);

    cout << boolalpha << graph.hasEdge(0, 1) << endl; // true
    cout << boolalpha << graph.hasEdge(1, 0) << endl; // false

    for (const auto& edge : graph.neighbors(2)) {
        cout << "2 -> " << edge.to << ", wight: " << edge.weight << endl;
    }
    // 2 -> 0, wight: 3
    // 2 -> 1, wight: 4

    graph.removeEdge(0, 1);
    cout << boolalpha << graph.hasEdge(0, 1) << endl; // false

    return 0;
}