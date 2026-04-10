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

## Traversal Order
| Type | Order |
|------|-------|
| Preorder | Root → Left → Right |
| Inorder | Left → Root → Right |
| Postorder | Left → Right → Root |
| Level-order | Level by level |

---

## Problems

| # | Problem | Time | Space | File |
|---|---------|------|-------|------|
| 01 | Preorder Traversal | O(n) | O(n) | [preorder.cpp](./01.%20preorder.cpp) |
| 02 | Inorder Traversal | O(n) | O(n) | [inorder.cpp](./02.%20inorder.cpp) |
| 03 | Postorder Traversal | O(n) | O(n) | [postorder.cpp](./03.%20postorder.cpp) |
| 04 | Level Order Traversal | O(n) | O(n) | [levelorder.cpp](./04.%20levelorder.cpp) |
| 05 | Maximum Depth | O(n) | O(h) | [MaximumDepth.cpp](./05.%20MaximumDepth.cpp) |
| 06 | Balanced Binary Tree | O(n) | O(h) | [BalancedBinaryTree.cpp](./06.%20BalancedBinaryTree.cpp) |
| 07 | Diameter of Tree | O(n) | O(h) | [Diameter.cpp](./07.%20Diameter.cpp) |
| 08 | Maximum Path Sum | O(n) | O(h) | [MaxPathSum.cpp](./08.%20MaxPathSum.cpp) |
| 09 | Building Tree | O(n) | O(n) | [BuildingTree.cpp](./09.%20BuildingTree.cpp) |
| 10 | Lowest Common Ancestor | O(n) | O(h) | [LCA.cpp](./10.%20LCA.cpp) |
| 11 | Right Side View | O(n) | O(h) | [RightSideView.cpp](./11.%20RightSideView.cpp) |
| 12 | Top View | O(n log n) | O(n) | [TopView.cpp](./12.%20TopView.cpp) |
| 13 | Vertical Order Traversal | O(n log n) | O(n) | [VerticalOrderTraversal.cpp](./13.%20VerticalOrderTraversal.cpp) |
| 14 | Validate BST | O(n) | O(h) | [ValidateBST.cpp](./14.%20ValidateBST.cpp) |
| 15 | Insert in BST | O(h) | O(h) | [Insert in BST.cpp](./15.%20Insert%20in%20BST.cpp) |

