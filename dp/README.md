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
| 05 | House Robber II | O(n) | O(1) | [House Robber II.cpp](./05.%20House%20Robber%20II.cpp) |
| 06 | Frog Jump | O(n) | O(1) | [Frog Jump.cpp](./06.%20Frog%20Jump.cpp) |
| 07 | Frog Jump with K Distance | O(n × k) | O(n) | [Frog Jump with K Distance.cpp](./07.%20Frog%20Jump%20with%20K%20Distance.cpp) |
| 08 | Ninja Training | O(n × 4 × 3) | O(n) | [Ninja Training.cpp](./08.%20Ninja%20Training.cpp) |
| 09 | Unique Paths | O(m × n) | O(n) | [Unique Paths.cpp](./09.%20Unique%20Paths.cpp) |
| 10 | Unique Paths II | O(m × n) | O(n) | [Unique Paths II.cpp](./10.%20Unique%20Paths%20II.cpp) |
| 11 | Minimum Path Sum | O(m × n) | O(n) | [Minimum Path Sum.cpp](./11.%20Minimum%20Path%20Sum.cpp) |

