//dael12345@gmail.com
#include "Algorithms.hpp"
#include"Queue.hpp"
#include"MinHeap.hpp"
#include"UnionFind.hpp"
#include <iostream>

namespace graph {
 /**
 * Performs Breadth-First Search (BFS) traversal on the given graph,
 * starting from the specified vertex.
 *
 * @param g The input graph (undirected).
 * @param start The starting vertex for the BFS traversal.
 * @return A new graph representing the BFS tree (spanning tree rooted at start).
 * @throws Exception if the graph is empty or the start vertex is invalid.
 */

    Graph Algorithms::bfs(const Graph& g, int start) {
        int n = g.getNumVertices();
        if (n <= 0) throw "Graph is empty.";
        if (start < 0 || start >= n) throw "this is not a valid start";
        Graph tree(n);
        bool* visited = new bool[n]{false};

        Queue q(n);
        q.enqueue(start);
        visited[start] = true;

        while (!q.isEmpty()) {
            int current = q.dequeue();
            Neighbor** adj = g.getAdjList();
            Neighbor* neighbor = adj[current];
            while (neighbor) {
                int v = neighbor->vertex;
                if (!visited[v]) {
                    visited[v] = true;
                    tree.addEdge(current, v, neighbor->weight);
                    q.enqueue(v);
                }
                neighbor = neighbor->next;
            }
        }

        delete[] visited;
        return tree;
    }

 /**
 * A utility function used by DFS to recursively visit vertices.
 *
 * @param g The input graph.
 * @param current The current vertex being visited.
 * @param visited A boolean array marking which vertices have been visited.
 * @param tree The DFS tree being constructed.
 */
    void Algorithms::dfsUtil(const Graph& g, int current, bool* visited, Graph& tree) {
        visited[current] = true;
        Neighbor** adj = g.getAdjList();
        Neighbor* neighbor =adj[current];
        while (neighbor) {
            int v = neighbor->vertex;
            if (!visited[v]) {
                tree.addEdge(current, v, neighbor->weight);
                dfsUtil(g, v, visited, tree);
            }
            neighbor = neighbor->next;
        }
    }

 /**
 * Performs Depth-First Search (DFS) traversal on the given graph,
 * starting from the specified vertex.
 *
 * @param g The input graph (undirected).
 * @param start The starting vertex for the DFS traversal.
 * @return A new graph representing the DFS tree (tree edges only).
 * @throws Exception if the graph is empty or the start vertex is invalid.
 */
    Graph Algorithms::dfs(const Graph& g, int start) {
        int n = g.getNumVertices();
        if (n <= 0) throw "Graph is empty";
        if (start < 0 || start >= n) throw "this is not a valid start";
        Graph tree(n);
        bool* visited = new bool[n]{false};
        dfsUtil(g, start, visited, tree);
        delete[] visited;
        return tree;
    }

/**
 * Computes the shortest path tree from a single source using Dijkstra's algorithm.
 *
 * @param g The input weighted graph with non-negative edge weights.
 * @param start The source vertex.
 * @return A new graph representing the shortest-path tree from the source.
 * @throws Exception if the graph is empty, the start vertex is invalid,
 *         or the graph contains a negative-weight edge.
 */
    Graph Algorithms::dijkstra(const Graph& g, int start) {
    int n = g.getNumVertices();
    if (n <= 0) throw "Graph is empty.";
    if (start < 0 || start >= n) throw "this is not a valid start";
    int* dist = new int[n];
    int* parent = new int[n];
    for (int i = 0; i < n; ++i) {
        dist[i] = 1e9;
        parent[i] = -1;
    }

    dist[start] = 0;
    MinHeap pq(n);
    for (int i = 0; i < n; ++i) {
        pq.insert(i, dist[i]);
    }

    while (!pq.isEmpty()) {
        int u = pq.extractMin();
        Neighbor** adj = g.getAdjList();
        Neighbor* neighbor = adj[u];
        while (neighbor) {
            int v = neighbor->vertex;
            int w = neighbor->weight;
            if (w < 0)
            throw "Dijkstra does not support negative edge weights";
            if (pq.contains(v) && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.decreaseKey(v, dist[v]);
            }
            neighbor = neighbor->next;
        }
    }

    Graph tree(n);
    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1)
            tree.addEdge(i, parent[i], dist[i] - dist[parent[i]]);
    }

    delete[] dist;
    delete[] parent;
    return tree;
    }

/**
 * Computes the Minimum Spanning Tree (MST) of the input graph using Prim's algorithm.
 *
 * @param g The input weighted graph (undirected).
 * @return A new graph representing the MST.
 * @throws Exception if the graph is empty or contains negative-weight edges.
 */
    Graph Algorithms::prim(const Graph& g) {
    int n = g.getNumVertices();
    if (n <= 0) throw "Graph is empty";
    int* key = new int[n];
    int* parent = new int[n];
    bool* inMST = new bool[n]{false};

    for (int i = 0; i < n; ++i) {
        key[i] = 1e9;
        parent[i] = -1;
    }

    key[0] = 0;
    MinHeap pq(n);
    for (int i = 0; i < n; ++i) {
        pq.insert(i, key[i]);
    }

    while (!pq.isEmpty()) {
        int u = pq.extractMin();
        inMST[u] = true;
        Neighbor** adj = g.getAdjList();
        Neighbor* neighbor = adj[u];
        while (neighbor) {
            int v = neighbor->vertex;
            int w = neighbor->weight;
            if (w < 0) throw "Prim does not support negative edge weights";
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.decreaseKey(v, key[v]);
            }
            neighbor = neighbor->next;
        }
    }

    Graph mst(n);
    for (int i = 1; i < n; ++i) {
        if (parent[i] != -1)
            mst.addEdge(i, parent[i], key[i]);
    }

    delete[] key;
    delete[] parent;
    delete[] inMST;
    return mst;
    }

/**
 * Computes the Minimum Spanning Tree (MST) of the input graph using Kruskal's algorithm.
 *
 * @param g The input weighted graph (undirected).
 * @return A new graph representing the MST.
 * @throws Exception if the graph is empty.
 */
    Graph Algorithms::kruskal(const Graph& g) {
    int n =g.getNumVertices();
    if (n <= 0) throw "Graph is empty.";
  
    Edge* edges = new Edge[n * n]; 
    int count = 0;
    for (int u = 0; u < n; ++u) {
        Neighbor** adj = g.getAdjList();
        Neighbor* neighbor = adj[u];
        while (neighbor) {
            int v = neighbor->vertex;
            if (u < v) {
                edges[count++] = {u, v, neighbor->weight};
            }
            neighbor = neighbor->next;
        }
    }

    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (edges[j].w > edges[j+1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }

    UnionFind uf(n);
    Graph mst(n);
    for (int i = 0; i < count; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            mst.addEdge(u, v, edges[i].w);
        }
    }

    delete[] edges;
    return mst;
    }

}
