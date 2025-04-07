//dael12345@gmail.com
#include <iostream>
#include "Graph.hpp"
#include"MinHeap.hpp"
#include "Algorithms.hpp"

using namespace graph;

    void printTitle(const std::string& title) {
    std::cout << "\n=== " << title << " ===\n";
}

int main() {

    Graph g(6);
    
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);

    printTitle("Original Graph");
    g.print_graph();


    // BFS
    Graph bfsTree = Algorithms::bfs(g, 0);
    printTitle("BFS Tree from vertex 0");
    bfsTree.print_graph();

    // DFS
    Graph dfsTree = Algorithms::dfs(g, 0);
    printTitle("DFS Tree from vertex 0");
    dfsTree.print_graph();

    // Dijkstra
    Graph dijkstraTree = Algorithms::dijkstra(g, 0);
    printTitle("Dijkstra Tree from vertex 0");
    dijkstraTree.print_graph();

    // Prim
    Graph primTree = Algorithms::prim(g);
    printTitle("Prim MST");
    primTree.print_graph();

    // Kruskal
    Graph kruskalTree = Algorithms::kruskal(g);
    printTitle("Kruskal MST");
    kruskalTree.print_graph();

    return 0;
}