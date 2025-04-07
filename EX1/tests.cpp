//dael12345@gmail.com
#include "Graph.hpp"
#include "Algorithms.hpp"
#include"Queue.hpp"
#include"MinHeap.hpp"
#include"UnionFind.hpp"
#include <cassert>
#include <iostream>

using namespace graph;

struct Edge {
    int u;
    int v;
};


bool edgeExists(const Edge* edges, int size, int u, int v) {
    for (int i = 0; i < size; ++i) {
        int a = edges[i].u;
        int b = edges[i].v;
        if ((a == u && b == v) || (a == v && b == u)) {
            return true;
        }
    }
    return false;
}

bool compareEdges(const Graph& g, const Edge* expected, int expectedSize) {
    int matched = 0;
    for (int i = 0; i < g.getNumVertices(); ++i) {
        Neighbor* n = g.getAdjList()[i];
        while (n) {
            int u = i;
            int v = n->vertex;
            if (u < v && edgeExists(expected, expectedSize, u, v)) {
                matched++;
            }
            n = n->next;
        }
    }
    return matched == expectedSize;
}

void testBFS() {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    Graph tree = Algorithms::bfs(g, 0);
    Edge expected[] = {
        {0, 1}, {0, 2}, {1, 3}, {2, 4}
    };
    assert(compareEdges(tree, expected, 4));
}

void testDFS() {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    Graph tree = Algorithms::dfs(g, 0);
    // ייתכנו כמה תוצאות חוקיות ל-DFS, נבחר אחת
    Edge expected[] = {
        {0, 1}, {1, 3}, {0, 2}, {2, 4}
    };
    assert(compareEdges(tree, expected, 4));
}

void testDijkstra() {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 2, 10);
    g.addEdge(2, 3, 1);

    Graph tree = Algorithms::dijkstra(g, 0);
    Edge expected[] = {
        {0, 1}, {1, 2}, {2, 3}
    };
    assert(compareEdges(tree, expected, 3));
}

void testPrim() {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 2);
    g.addEdge(0, 3, 5);

    Graph tree = Algorithms::prim(g);
    Edge expected[] = {
        {0, 1}, {1, 2}, {2, 3}
    };
    assert(compareEdges(tree, expected, 3));
}

void testKruskal() {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 2);
    g.addEdge(0, 3, 5);

    Graph tree = Algorithms::kruskal(g);
    Edge expected[] = {
        {0, 1}, {1, 2}, {2, 3}
    };
    assert(compareEdges(tree, expected, 3));
}
void testQueue() {
    graph::Queue q(5);
    assert(q.isEmpty());

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    assert(!q.isEmpty());

    assert(q.dequeue() == 1);
    assert(q.dequeue() == 2);
    assert(q.dequeue() == 3);
    assert(q.isEmpty());
}
void testMinHeap() {
    graph::MinHeap heap(5);
    heap.insert(0, 5);
    heap.insert(1, 3);
    heap.insert(2, 4);

    assert(!heap.isEmpty());
    assert(heap.extractMin() == 1);  
    assert(heap.extractMin() == 2);
    assert(heap.extractMin() == 0);
    assert(heap.isEmpty());
}
void testUnionFind() {
    graph::UnionFind uf(4);
    assert(uf.find(0) == 0);
    uf.unite(0, 1);
    assert(uf.find(0) == uf.find(1));

    uf.unite(2, 3);
    assert(uf.find(2) == uf.find(3));

    uf.unite(1, 3);
    assert(uf.find(0) == uf.find(2));
}
void testGraphBasics() {
    Graph g(3);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);

    Neighbor** adj = g.getAdjList();
    assert(adj[0]->vertex == 1);
    assert(adj[1]->vertex == 2 || adj[1]->vertex == 0);
    assert(g.getNumVertices() == 3);
}

int main() {
    std::cout << "Running tests\n" << std::endl;

    testBFS();
    testDFS();
    testDijkstra();
    testPrim();
    testKruskal();
    testQueue();
    testMinHeap();
    testUnionFind();
    testGraphBasics();

    std::cout << "\n All tests passed!" << std::endl;
    return 0;
}