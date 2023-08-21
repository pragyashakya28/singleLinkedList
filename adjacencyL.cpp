#include <iostream>
#include "singleLL.cpp" 

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

    void removeEdge(int from, int to) {
        if (from >= 0 && from < nodes) {
            adjacency[from].remove(to);
        }
    }

    bool hasEdge(int from, int to) {
        if (from >= 0 && from < nodes) {
            return adjacency[from].contains(to);
        }
        return false;
    }

    void displayList() {
        for (int i = 0; i < nodes; ++i) {
            std::cout << "Node " << i << " -> ";
            adjacency[i].display();
        }
    }
};

int main() {
    int nodes, edges;
    std::cout << "Enter the number of nodes in the graph: ";
    std::cin >> nodes;
    std::cout << "Enter the number of edges in the graph: ";
    std::cin >> edges;

    AdjacencyList graph(nodes);

    std::cout << "Enter the edges (from to):" << std::endl;
    for (int i = 0; i < edges; ++i) {
        int from, to;
        std::cin >> from >> to;
        graph.addEdge(from, to);
    }
    
    
    /*
    int fromNode, toNode;
    std::cout << "Enter the source node: ";
    std::cin >> fromNode;
    std::cout << "Enter the destination node: ";
    std::cin >> toNode;
    graph.removeEdge(fromNode, toNode);



    int fromNode1, toNode1;
    std::cout << "Enter the source node: ";
    std::cin >> fromNode1;
    std::cout << "Enter the destination node: ";
    std::cin >> toNode1;

    bool hasEdge = graph.hasEdge(fromNode1, toNode1);
    if (hasEdge) {
    	std::cout << "There is an edge between " << fromNode1 << " and " << toNode1 << std::endl;
    } else {
    	std::cout << "There is no edge between " << fromNode1<< " and " << toNode1 << std::endl;
    }
    */

    std::cout << "Adjacency List:" << std::endl;
    graph.displayList();

    return 0;
}

