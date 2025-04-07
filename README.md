# Graph Algorithms Project - README

## Student Info

- **Name:** Dael
- **Email:** [dael12345@gmail.com](mailto\:dael12345@gmail.com)

---

## Project Overview

This project implements an undirected weighted graph using an adjacency list and includes a variety of algorithms for traversing and analyzing graphs. All data structures were implemented manually **without using the C++ STL**, as required.

---

## Implemented Classes

### 1. `Graph`

- Represents an undirected graph using an adjacency list.
- Main features:
  - `addEdge(from, to, weight)` - Adds an undirected edge.
  - `removeEdge(from, to)` - Removes an undirected edge.
  - `print_graph()` - Prints the adjacency list.
  - Input validation and exception handling included.

### 2. `Algorithms`

Contains implementations for:

- **BFS** – Builds a BFS tree from a given start vertex.
- **DFS** – Builds a DFS tree from a given start vertex.
- **Dijkstra** – Computes the shortest paths from a given source (no negative weights allowed).
- **Prim** – Builds a minimum spanning tree (no negative weights, checks for connectedness).
- **Kruskal** – Builds a minimum spanning tree using union-find (allows negative weights).

All functions throw exceptions for invalid input or unsupported cases.

### 3. `Queue`

- Implements a circular queue using a raw array.
- Functions:
  - `enqueue(value)`, `dequeue()`, `isEmpty()`

### 4. `MinHeap`

- Custom priority queue used in Dijkstra and Prim algorithms.
- Maintains vertex-distance pairs.
- Functions:
  - `insert(v, dist)`, `extractMin()`, `decreaseKey(v, dist)`, `contains(v)`, `getDist(v)`

### 5. `UnionFind`

- Supports Kruskal’s algorithm.
- Efficient union and find with path compression and union by rank.

---

## Input Validation and Exceptions

- All algorithms check for:
  - Invalid start vertex
  - Empty graph
  - Negative edge weights (where not allowed)
- Functions throw descriptive exceptions when invalid input is provided.

---

## Memory Management

- Manual dynamic allocation (`new` / `delete`) used throughout.
- Verified with `valgrind` to ensure there are no memory leaks.

---

## Compilation and Running

- Use the provided `Makefile`:
  - `make Main` – Compiles and runs the main demo.
  - `make test` – Runs unit tests.
  - `make valgrind` – Checks for memory leaks.
  - `make clean` – Removes all generated files.

---

## Additional Notes

- Each class is implemented in its own `.cpp` and `.hpp` files.
- A test suite using `assert` ensures all algorithms and data structures work correctly.
