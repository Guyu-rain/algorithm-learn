#include <iostream>
#include <vector>

class WeightedDigraph {
private:
    // 邻接矩阵，matrix[from][to] 存储从节点 from 到 to 的边的权重
    // 0 表示没有连接
    std::vector<std::vector<int>> matrix;

public:
    // 用来存储相邻节点及其边权
    struct Edge {
        int to;
        int weight;

        Edge(int to, int weight) : to(to), weight(weight) {}
    };

    WeightedDigraph(int n) {
        matrix = std::vector<std::vector<int>>(n, std::vector<int>(n, 0)); 
    }

    // 增，添加一条带权重的有向边，复杂度 O(1)
    void addEdge(int from, int to, int weight) {
        matrix[from][to] = weight;
    }

    // 删，删除一条有向边，复杂度 O(1)
    void removeEdge(int from, int to) {
        matrix[from][to] = 0;
    }

    // 查，判断两个节点是否相邻，复杂度 O(1)
    bool hasEdge(int from, int to) {
        return matrix[from][to] != 0;
    }

    // 查，返回一条边的权重，复杂度 O(1)
    int weight(int from, int to) {
        return matrix[from][to];
    }

    // 查，返回某个节点所有的邻居节点，复杂度 O(v)
    std::vector<Edge> neighbors(int v) {
        std::vector<Edge> res;
        for (int i = 0; i < matrix[v].size(); i++) {
            if (matrix[v][i] != 0) {
                res.emplace_back(i, matrix[v][i]);
            }
        }
        return res;
    }
};

// 调试
int main() {
    WeightedDigraph graph(3);
    graph.addEdge(0, 1, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 0, 3);
    graph.addEdge(2, 1, 4);

    std::cout << std::boolalpha;
    std::cout << graph.hasEdge(0, 1) << std::endl; // true
    std::cout << graph.hasEdge(1, 0) << std::endl; // false

    for (const auto& edge : graph.neighbors(2)) {
        std::cout << "2 -> " << edge.to << ", weight: " << edge.weight << std::endl;
    }
    // 2 -> 0, weight: 3
    // 2 -> 1, weight: 4

    graph.removeEdge(0, 1);
    std::cout << graph.hasEdge(0, 1) << std::endl; // false

    return 0;
}