//dael12345@gmail.com
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.hpp"

namespace graph {

    class Algorithms {
    public:
        static Graph bfs(const Graph& g, int start);
        static Graph dfs(const Graph& g, int start);
        static Graph dijkstra(const Graph& g, int start);
        static Graph prim(const Graph& g);
        static Graph kruskal(const Graph& g);

    private:
        static void dfsUtil(const Graph& g, int current, bool* visited, Graph& tree);
        struct Edge {
            int u, v, w;
        };


    };
    

}

#endif