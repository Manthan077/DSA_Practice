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

## Complexities

| Pattern | Time | Space |
|---------|------|-------|
| 1D DP | O(n) | O(n) or O(1) |
| 2D DP | O(n²) | O(n²) or O(n) |
| Knapsack | O(n × W) | O(n × W) or O(W) |
| Interval DP | O(n³) | O(n²) |
| Bitmask DP | O(2ⁿ × n) | O(2ⁿ × n) |

---

## Key Problems
- Coin change, house robber, word break
- Longest common subsequence, LIS
- 0/1 knapsack, partition equal subset
- Edit distance, burst balloons, palindrome partitioning

