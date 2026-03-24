# Trees

A tree is a hierarchical data structure made of nodes connected by edges, with no cycles. Every tree has a root, and each node can have zero or more children.

---

## Types
- **Binary Tree** — each node has at most 2 children
- **BST** — left < root < right, O(log n) search on average
- **AVL / Red-Black Tree** — self-balancing BSTs, guarantee O(log n) height
- **Trie** — each node is a character, used for prefix/string search
- **Heap** — complete binary tree, min-heap or max-heap, backs priority queues
- **Segment Tree** — range queries and point updates in O(log n)

---

## Traversals
| Type | Order | Use Case | File |
|------|-------|----------|------|
| Preorder | Root → Left → Right | Serialize / copy a tree | [01. preorder.cpp](./01.%20preorder.cpp) |
| Inorder | Left → Root → Right | Sorted output from BST | [02. inorder.cpp](./02.%20inorder.cpp) |
| Postorder | Left → Right → Root | Delete tree, expression eval | [03. postorder.cpp](./03.%20postorder.cpp) |
| Level-order | Level by level | Shortest path, level-wise processing | [04. levelorder.cpp](./04.%20levelorder.cpp) |

---

## Complexities

| Traversal | Time | Space |
|-----------|------|-------|
| Preorder | O(n) | O(n) |
| Inorder | O(n) | O(n) |
| Postorder | O(n) | O(n) |
| Level-order | O(n) | O(n) |

---

## Key Problems
- Height, diameter, lowest common ancestor (LCA)
- Validate BST, serialize/deserialize
- Path sum, right side view, construct from traversals

