# Dynamic Programming

DP solves problems by breaking them into overlapping subproblems and caching results to avoid recomputation.

A problem fits DP if it has:
1. **Optimal Substructure** — optimal answer built from optimal subanswers
2. **Overlapping Subproblems** — same subproblems repeat

---

## Approaches
- **Top-Down (Memoization)** — recursive + cache, natural to write
- **Bottom-Up (Tabulation)** — iterative table, avoids recursion overhead

---

## Patterns
| Pattern | Examples |
|---------|----------|
| 1D DP | Climbing stairs, house robber, jump game |
| 2D DP | Grid paths, edit distance |
| Knapsack | 0/1 knapsack, subset sum, coin change |
| Subsequences | LCS, LIS, edit distance |
| Interval DP | Burst balloons, matrix chain multiplication |
| DP on Trees | Max path sum, house robber III |
| Bitmask DP | TSP, task assignment (small n) |

---

## Problems

| # | Problem | Time | Space | File |
|---|---------|------|-------|------|
| 01 | Fibonacci | O(n) | O(1) | [Fibonacci.cpp](./01.%20Fibonacci.cpp) |
| 02 | Climbing Stairs | O(n) | O(1) | [Climbing Stairs.cpp](./02.%20Climbing%20Stairs.cpp) |
| 03 | Min Cost Climbing Stairs | O(n) | O(1) | [Min cost climbing stairs.cpp](./03.%20Min%20cost%20climbing%20stairs.cpp) |
| 04 | House Robber | O(n) | O(1) | [House Robber.cpp](./04.%20House%20Robber.cpp) |

