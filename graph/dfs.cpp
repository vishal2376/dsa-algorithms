#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int num_vertices;
    vector<int> *adjacency_list;

    void dfs_util(int vertex, bool visited[]) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < adjacency_list[vertex].size(); i++) {
            int adjacent_vertex = adjacency_list[vertex][i];
            if (!visited[adjacent_vertex]) {
                dfs_util(adjacent_vertex, visited);
            }
        }
    }

public:
    Graph(int V) {
        num_vertices = V;
        adjacency_list = new vector<int>[V];
    }

    void add_edge(int src, int dest) {
        adjacency_list[src].push_back(dest);
        adjacency_list[dest].push_back(src); // Uncomment this line for undirected graphs
    }

    void dfs(int start_vertex) {
        bool visited[num_vertices] = {false};

        dfs_util(start_vertex, visited);
    }
};

int main() {
    Graph graph(5);
    graph.add_edge(0, 1);
    graph.add_edge(0, 4);
    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    graph.add_edge(1, 4);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);

    graph.dfs(0); // Starting DFS from vertex 0

    return 0;
}
