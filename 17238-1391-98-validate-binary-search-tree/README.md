<h2> 17238 1391
98. Validate Binary Search Tree</h2><hr><div><p>Given the <code>root</code> of a binary tree, <em>determine if it is a valid binary search tree (BST)</em>.</p>

<p>A <strong>valid BST</strong> is defined as follows:</p>

<ul>
	<li>The left <span data-keyword="subtree">subtree</span> of a node contains only nodes with keys <strong>less than</strong> the node's key.</li>
	<li>The right subtree of a node contains only nodes with keys <strong>greater than</strong> the node's key.</li>
	<li>Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg" style="width: 302px; height: 182px;">
<pre><strong>Input:</strong> root = [2,1,3]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg" style="width: 422px; height: 292px;">
<pre><strong>Input:</strong> root = [5,1,4,null,null,3,6]
<strong>Output:</strong> false
<strong>Explanation:</strong> The root node's value is 5 but its right child's value is 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-2<sup>31</sup> &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
</ul>
</div>

# Validate Binary Search Tree (IsValidBST)

This solution checks if a binary tree is a valid Binary Search Tree (BST) using **Post-order Traversal**. It ensures that every node satisfies the BST property: 
- **All nodes in the left subtree** must be smaller than their parent.
- **All nodes in the right subtree** must be larger than their parent.

## Problem Definition

A Binary Search Tree is valid if:
1. The left subtree of a node contains only nodes with keys less than the node's key.
2. The right subtree of a node contains only nodes with keys greater than the node's key.
3. Both the left and right subtrees must also be binary search trees.

## Implementation

This solution uses a helper function `IsValidBSTPostOrderTraversal` with parameters for the node and its allowable range (`min` and `max`). The traversal:
1. Validates the left subtree recursively.
2. Validates the right subtree recursively.
3. Ensures the current node's value is within the allowable range (`min < node.val < max`).

## Complexity
- Time Complexity: 𝑂(𝑛), where 𝑛 is the number of nodes in the tree. Each node is visited exactly once.
- Space Complexity: 𝑂(ℎ), where ℎ is the height of the tree, due to the recursive call stack.
