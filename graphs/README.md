# Graphs

A graph is a set of vertices connected by edges. Unlike trees, graphs can have cycles, multiple components, and weighted or directed edges.

---

## Representations
- **Adjacency List** — O(V + E) space, efficient for sparse graphs
- **Adjacency Matrix** — O(V²) space, O(1) edge lookup
- **Edge List** — flat list of edges, used in Kruskal's

---

## Traversals
- **BFS** — level-by-level using a queue, finds shortest path in unweighted graphs
- **DFS** — depth-first using recursion/stack, used for cycle detection and topological sort

---

## Key Algorithms
- **Topological Sort** — Kahn's (BFS) or DFS-based, works on DAGs
- **Dijkstra** — shortest path, no negative weights
- **Bellman-Ford** — handles negative weights
- **Floyd-Warshall** — all-pairs shortest path
- **Union-Find** — track connected components
- **Kruskal / Prim** — minimum spanning tree

---

## Problems

| # | Problem | Time | Space | File |
|---|---------|------|-------|------|
| 01 | Graph Representation | O(V + E) | O(V + E) | [Graph Representation.cpp](./01.%20Graph%20Representation.cpp) |
| 02 | DFS | O(V + E) | O(V) | [DFS.cpp](./02.%20DFS.cpp) |
| 03 | BFS | O(V + E) | O(V) | [BFS.cpp](./03.%20BFS.cpp) |
| 04 | Connected Components | O(V + E) | O(V) | [Connected Components.cpp](./04.%20Connected%20Components.cpp) |
| 05 | Number of Islands | O(n × m) | O(n × m) | [Number of Islands.cpp](./05.%20Number%20of%20Islands.cpp) |
| 06 | Flood Fill | O(n × m) | O(n × m) | [Flood Fill.cpp](./06.%20Flood%20Fill.cpp) |
| 07 | Cycle Detection Undirected (BFS) | O(V + E) | O(V) | [Cycle Detection Undirected.cpp](./07.%20Cycle%20Detection%20in%20Undirected%20Graph.cpp) |
| 08 | Cycle Detection Undirected (DFS) | O(V + E) | O(V) | [Cycle Detection Undirected DFS.cpp](./08.%20Cycle%20Detection%20in%20Undirected%20Graph%20(DFS).cpp) |
| 09 | Cycle Detection Directed (DFS) | O(V + E) | O(V) | [Cycle Detection Directed.cpp](./09.%20Cycle%20Detection%20in%20Directed%20Graph%20(DFS).cpp) |
| 10 | Topological Sort (Kahn's) | O(V + E) | O(V) | [Topological Sort Kahn.cpp](./10.%20Topological%20Sort%20(Kahn%27s%20Algorithm).cpp) |
| 11 | Topological Sort (DFS) | O(V + E) | O(V) | [Topological Sort DFS.cpp](./11.%20DFS%20Topological%20Sort%20(Stack).cpp) |

