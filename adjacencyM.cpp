#include <iostream>
#include <map>
#include "array.cpp" // Include the array implementation

const int MAX_NODES = 100; // Maximum number of nodes in the graph

template <typename T>
class AdjacencyMatrix {
private:
    Array<T>* matrix;
    std::map<int, T> edgeWeights; // Map to store edge weights
    int nodes;
    bool isUndirected;

public:
    AdjacencyMatrix(int n, bool undirected) : nodes(n), isUndirected(undirected) {
        matrix = new Array<T>(n * n);
    }

    void addEdge(int from, int to, T weight) {
        if (from >= 0 && from < nodes && to >= 0 && to < nodes) {
            matrix->insert(from * nodes + to);
            if (isUndirected) {
                matrix->insert(to * nodes + from); // For undirected graph
            }
            edgeWeights[from * nodes + to] = weight;
            if (isUndirected) {
                edgeWeights[to * nodes + from] = weight;
            }
        }
    }

    void displayMatrix() {
        for (int i = 0; i < nodes; ++i) {
            for (int j = 0; j < nodes; ++j) {
                int value = matrix->get(i * nodes + j);
                if (value != 0) {
                    T weight = edgeWeights[i * nodes + j];
                    std::cout << weight << " ";
                } else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }

    ~AdjacencyMatrix() {
        delete matrix;
    }
};

int main() {
    int nodes, edges;
    bool isUndirected;

    std::cout << "Choose graph type:" << std::endl;
    std::cout << "1. Directed" << std::endl;
    std::cout << "2. Undirected" << std::endl;
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        isUndirected = false;
    } else if (choice == 2) {
        isUndirected = true;
    } else {
        std::cout << "Invalid choice." << std::endl;
        return 1;
    }

    std::cout << "Enter the number of nodes in the graph: ";
    std::cin >> nodes;

    AdjacencyMatrix<int> graph(nodes, isUndirected);

    std::cout << "Enter the number of edges in the graph: ";
    std::cin >> edges;

    std::cout << "Enter the edges and weights (from to weight):" << std::endl;
    for (int i = 0; i < edges; ++i) {
        int from, to, weight;
        std::cin >> from >> to >> weight;
        graph.addEdge(from, to, weight);
    }

    std::cout << "Adjacency Matrix:" << std::endl;
    graph.displayMatrix();

    return 0;
}

