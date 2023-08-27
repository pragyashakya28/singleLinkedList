#include<iostream>
#include"singleLL.cpp"
#include"queueA.cpp"

const int MAX_NODES = 100;

class AdjacencyList {
private:
    LinkedList<int> adjacency[MAX_NODES];
    int nodes;

public:
    AdjacencyList(int n) : nodes(n) {}

    void addEdge(int from, int to) {
        if (from >= 0 && from < nodes) {
            adjacency[from].insert(to);
        }
    }


    void BFS(int start_vertex) {
        bool visited[MAX_NODES] = {false};
        Queue<int> bfs_queue(nodes);

        visited[start_vertex] = true;
        bfs_queue.enqueue(start_vertex);

        while (!bfs_queue.isEmpty()) {
            int current_vertex = bfs_queue.front();
            bfs_queue.dequeue();
            std::cout << current_vertex << " ";

            Node<int>* current = adjacency[current_vertex].getHead();
            while (current) {
                if (!visited[current->getData()]) {
                    visited[current->getData()] = true;
                    bfs_queue.enqueue(current->getData());
                }
                current = current->getNext();
            }
        }
        std::cout << std::endl;
    }
};


int main() {
    int numNodes, numEdges, startVertex;
    std::cout << "Enter the number of nodes: ";
    std::cin >> numNodes;

    AdjacencyList graph(numNodes);

    std::cout << "Enter the number of edges: ";
    std::cin >> numEdges;
    for (int i = 0; i < numEdges; ++i) {
        int from, to;
        std::cout << "Enter edge " << i + 1 << " (from to): ";
        std::cin >> from >> to;
        graph.addEdge(from, to);
    }

    std::cout << "Enter the starting vertex for BFS: ";
    std::cin >> startVertex;

    std::cout << "BFS starting from vertex " << startVertex << ": ";
    graph.BFS(startVertex);

    return 0;
}
