#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<int> *adjList;

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjList = new vector<int>[numVertices];
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": ";
            for (auto j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.printGraph();

    return 0;
}
