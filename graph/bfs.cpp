
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int num_vertices;
    vector<int> *adjacency_list;

public:
    Graph(int V) {
        num_vertices = V;
        adjacency_list = new vector<int>[V];
    }

    void add_edge(int src, int dest) {
        adjacency_list[src].push_back(dest);
        adjacency_list[dest].push_back(src); // Uncomment this line for undirected graphs
    }

    void bfs(int start_vertex) {
        bool visited[num_vertices] = {false};
        queue<int> q;

        visited[start_vertex] = true;
        q.push(start_vertex);

        while (!q.empty()) {
            int curr_vertex = q.front();
            cout << curr_vertex << " ";
            q.pop();

            for (int i = 0; i < adjacency_list[curr_vertex].size(); i++) {
                int adjacent_vertex = adjacency_list[curr_vertex][i];
                if (!visited[adjacent_vertex]) {
                    visited[adjacent_vertex] = true;
                    q.push(adjacent_vertex);
                }
            }
        }
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

    graph.bfs(0); // Starting BFS from vertex 0

    return 0;
}

