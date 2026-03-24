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

## Complexities

| Algorithm | Time | Space |
|-----------|------|-------|
| BFS | O(V + E) | O(V) |
| DFS | O(V + E) | O(V) |
| Topological Sort | O(V + E) | O(V) |
| Dijkstra | O((V + E) log V) | O(V) |
| Bellman-Ford | O(V × E) | O(V) |
| Floyd-Warshall | O(V³) | O(V²) |
| Kruskal | O(E log E) | O(V) |
| Prim | O((V + E) log V) | O(V) |

---

## Key Problems
- Number of islands, detect cycle, bipartite check
- Course schedule (topological sort), word ladder (BFS)
- Dijkstra shortest path, critical connections

