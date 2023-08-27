#include<iostream>
#include"stackA.cpp"
#include"singleLL.cpp"

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


    void DFS(int start_vertex) {
        bool visited[MAX_NODES] = {false};
        Stack<int> dfs_stack(nodes);

        dfs_stack.push(start_vertex);

        while (!dfs_stack.isEmpty()) {
            int current_vertex = dfs_stack.peek();
            dfs_stack.pop();

            if (!visited[current_vertex]) {
                visited[current_vertex] = true;
                std::cout << current_vertex << " ";

                Node<int>* current = adjacency[current_vertex].getHead();
                while (current) {
                    if (!visited[current->getData()]) {
                        dfs_stack.push(current->getData());
                    }
                    current = current->getNext();
                }
            }
        }
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

    std::cout << "Enter the starting vertex for DFS: ";
    std::cin >> startVertex;

    std::cout << "DFS starting from vertex " << startVertex << ": ";
    graph.DFS(startVertex);
    std::cout << std::endl;

    return 0;
}
