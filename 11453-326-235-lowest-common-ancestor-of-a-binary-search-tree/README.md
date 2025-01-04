<h2> 11453 326
235. Lowest Common Ancestor of a Binary Search Tree</h2><hr><div><p>Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.</p>

<p>According to the <a href="https://en.wikipedia.org/wiki/Lowest_common_ancestor" target="_blank">definition of LCA on Wikipedia</a>: “The lowest common ancestor is defined between two nodes <code>p</code> and <code>q</code> as the lowest node in <code>T</code> that has both <code>p</code> and <code>q</code> as descendants (where we allow <strong>a node to be a descendant of itself</strong>).”</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png" style="width: 200px; height: 190px;">
<pre><strong>Input:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
<strong>Output:</strong> 6
<strong>Explanation:</strong> The LCA of nodes 2 and 8 is 6.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png" style="width: 200px; height: 190px;">
<pre><strong>Input:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> root = [2,1], p = 2, q = 1
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[2, 10<sup>5</sup>]</code>.</li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li>All <code>Node.val</code> are <strong>unique</strong>.</li>
	<li><code>p != q</code></li>
	<li><code>p</code> and <code>q</code> will exist in the BST.</li>
</ul>
</div>

# Lowest Common Ancestor (LCA) Solution

## Problem Overview
The task is to find the **Lowest Common Ancestor (LCA)** of two nodes (`p` and `q`) in a **binary tree**. The **LCA** is defined as the deepest node that is an ancestor to both `p` and `q`. We approach this problem using a method that builds the paths from the root to the nodes and finds the last common node.

## Approach

### Step 1: Path Discovery
We start by finding the paths from the root node to both `p` and `q`. We use a helper function `FindPath` to do this:
- Traverse the tree recursively.
- For each node, we add it to the path if it’s part of the path from the root to the target node.
- If the target node is found, we return `true`, and if not, we backtrack.

### Step 2: Compare the Paths
Once we have the paths from the root to `p` and from the root to `q`, we compare them:
- We compare each node in both paths.
- The first divergence (i.e., where the nodes in the paths don’t match) gives us the **last common node**, which is the **LCA**.

### Step 3: Return the LCA
The node where the paths diverge is the **LCA**. If the paths are identical up to a certain point, that node is the **LCA**. We return the last matching node.
