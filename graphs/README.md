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
| 12 | Shortest Path in Unweighted Graph | O(V + E) | O(V) | [Shortest Path Unweighted.cpp](./12.%20Shortest%20Path%20in%20Unweighted%20Graph.cpp) |
| 13 | Dijkstra Algorithm | O((V + E) log V) | O(V) | [Dijkstra Algorithm.cpp](./13.%20Dijkstra%20Algorithm.cpp) |
| 14 | Bellman Ford Algorithm | O(V × E) | O(V) | [Bellman Ford Algorithm.cpp](./14.%20Bellman%20Ford%20Algorithm.cpp) |
| 15 | Floyd Warshall Algorithm | O(V³) | O(V²) | [Floyd Warshall Algorithm.cpp](./15.%20Floyd%20Warshall%20Algorithm.cpp) |
| 16 | Disjoint Set Union | O(α(n)) | O(V) | [Disjoint Set Union.cpp](./16.%20Disjoint%20Set%20Union.cpp) |
| 17 | Redundant Connection | O(E × α(n)) | O(V) | [Redundant Connection.cpp](./17.%20Redundant%20Connection.cpp) |
| 18 | Accounts Merge | O(n × m × α(n)) | O(n) | [Accounts Merge.cpp](./18.%20Accounts%20Merge.cpp) |
| 19 | Kruskal's Algorithm | O(E log E) | O(V) | [Kruskal's Algorithm.cpp](./19.%20Kruskal%27s%20Algorithm.cpp) |
| 20 | Prim's Algorithm | O((V + E) log V) | O(V) | [Prim's Algorithm.cpp](./20.%20Prim%27s%20Algorithm.cpp) |
| 21 | Number of Provinces using DSU | O(V² × α(n)) | O(V) | [Number of Provinces using DSU.cpp](./21.%20Number%20of%20Provinces%20using%20DSU.cpp) |
| 22 | Number of Operations to Make Network Connected | O(E × α(n)) | O(V) | [Network Connected.cpp](./22.%20Number%20of%20Operations%20to%20Make%20Network%20Connected.cpp) |
| 23 | Bridges in Graph (Tarjan's) | O(V + E) | O(V) | [Bridges in Graph.cpp](./23.%20Bridges%20in%20Graph%20(Tarjan%27s%20Algorithm).cpp) |
| 24 | Articulation Point (Cut Vertex) | O(V + E) | O(V) | [Articulation Point.cpp](./24.%20Articulation%20Point%20(Cut%20Vertex).cpp) |
| 25 | Kosaraju Algorithm | O(V + E) | O(V) | [Kosaraju Algorithm.cpp](./25.%20Kosaraju%20Algorithm.cpp) |
| 26 | Word Ladder | O(N × L × 26) | O(N) | [Word Ladder.cpp](./26.%20Word%20Ladder.cpp) |
| 27 | Alien Dictionary | O(V + E) | O(V) | [Alien Dictionary.cpp](./27.%20Alien%20Dictionary.cpp) |
| 28 | Course Schedule I | O(V + E) | O(V) | [Course Schedule I.cpp](./28.%20Course%20Schedule%20I.cpp) |
| 29 | Course Schedule II | O(V + E) | O(V) | [Course Schedule II.cpp](./29.%20Course%20Schedule%20II.cpp) |
| 30 | Rotting Oranges | O(n × m) | O(n × m) | [Rotting Oranges.cpp](./30.%20Rotting%20Oranges.cpp) |
| 31 | 01 Matrix | O(n × m) | O(n × m) | [01 Matrix.cpp](./31.%2001%20Matrix.cpp) |
| 32 | Cheapest Flights Within K Stops | O(E × K) | O(V) | [Cheapest Flights Within K Stops.cpp](./32.%20Cheapest%20Flights%20Within%20K%20Stops.cpp) |

