<h2> 11827 238
230. Kth Smallest Element in a BST</h2><hr><div><p>Given the <code>root</code> of a binary search tree, and an integer <code>k</code>, return <em>the</em> <code>k<sup>th</sup></code> <em>smallest value (<strong>1-indexed</strong>) of all the values of the nodes in the tree</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg" style="width: 212px; height: 301px;">
<pre><strong>Input:</strong> root = [3,1,4,null,2], k = 1
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg" style="width: 382px; height: 302px;">
<pre><strong>Input:</strong> root = [5,3,6,2,4,null,null,1], k = 3
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is <code>n</code>.</li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?</p>
</div>

# K-th Smallest Element in a Binary Search Tree (BST)

This solution finds the **K-th smallest element** in a Binary Search Tree (BST) using **in-order traversal**. Here’s a detailed breakdown of the problem, approach, implementation, and complexity analysis.

---

## Problem Description
Given the root of a binary search tree (BST) and an integer `k`, find the K-th smallest element in the BST. A BST is a binary tree where:
1. The left subtree contains only nodes with values less than the parent node.
2. The right subtree contains only nodes with values greater than the parent node.
3. Both subtrees are also binary search trees.

---

## Approach

### Why In-Order Traversal?
A Fact about the BST --> The k-th visited node is the K-th smallest element in the tree
In-order traversal of a BST visits the nodes in **ascending order**. This means:
1. Traverse the left subtree.
2. Visit the root node.
3. Traverse the right subtree.

By counting the nodes visited during this traversal, the K-th visited node is the K-th smallest element in the tree.

---

## Steps to Solve
1. **Perform an In-Order Traversal**:
   - Visit nodes in the left subtree first (smaller values).
   - Count each visited node.
   - When the count reaches `k`, record the value of the current node as the answer.
   - If `k` is found, stop the traversal early to avoid unnecessary operations.

2. **Recursive Implementation**:
   - A helper function, `KthSmallestInorderTraversal`, is used for the in-order traversal.
   - Use a counter (`count`) to track the position during traversal.
   - Store the result in a variable (`answer`) once the K-th smallest element is identified.

---

## Time Complexity: O(n)
## Space Comlexity: O(n)
