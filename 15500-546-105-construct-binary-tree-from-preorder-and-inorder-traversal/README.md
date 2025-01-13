<h2> 15500 546
105. Construct Binary Tree from Preorder and Inorder Traversal</h2><hr><div><p>Given two integer arrays <code>preorder</code> and <code>inorder</code> where <code>preorder</code> is the preorder traversal of a binary tree and <code>inorder</code> is the inorder traversal of the same tree, construct and return <em>the binary tree</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree.jpg" style="width: 277px; height: 302px;">
<pre><strong>Input:</strong> preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
<strong>Output:</strong> [3,9,20,null,null,15,7]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> preorder = [-1], inorder = [-1]
<strong>Output:</strong> [-1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= preorder.length &lt;= 3000</code></li>
	<li><code>inorder.length == preorder.length</code></li>
	<li><code>-3000 &lt;= preorder[i], inorder[i] &lt;= 3000</code></li>
	<li><code>preorder</code> and <code>inorder</code> consist of <strong>unique</strong> values.</li>
	<li>Each value of <code>inorder</code> also appears in <code>preorder</code>.</li>
	<li><code>preorder</code> is <strong>guaranteed</strong> to be the preorder traversal of the tree.</li>
	<li><code>inorder</code> is <strong>guaranteed</strong> to be the inorder traversal of the tree.</li>
</ul>
</div>

# Reconstruct Binary Tree from Preorder and Inorder Traversals

This provides an optimized solution for reconstructing a binary tree from its preorder and inorder traversal arrays. The implementation leverages a dictionary to achieve better performance.

## Problem Description

Given two arrays:
1. `preorder`: The preorder traversal of a binary tree.
2. `inorder`: The inorder traversal of the same binary tree.

The task is to reconstruct and return the binary tree efficiently.

Facts about the preorder and inorder traversals of the binary tree
preorder output: root --> left subtree --> right subtree
inorder output:  left subtree --> root --> right subtree
so from the preorder we can know the roots of each subtree we call the recursive function for it and from the inorder we know the left and the right subtrees for each root in the recursive call.


## Approach

### Steps to Solve:
1. **Identify the Root**:
   - The first element in the `preorder` array is always the root of the current subtree.
2. **Divide the Subtree**:
   - Use the root's index in the `inorder` array to split it into left and right subtrees.
3. **Recursive Construction**:
   - Recursively construct the left and right subtrees using the divided parts of the `inorder` array and the corresponding elements in the `preorder` array.

### Optimization:
- Use a dictionary (`inorderMap`) to store the indices of values in the `inorder` array.
- This eliminates the need for a linear search to find the root index, improving the overall time complexity.

---

## Complexity Analysis

### Time Complexity:
- **Dictionary Creation**: \(O(n)\), where \(n\) is the number of nodes.
- **Tree Construction**: \(O(n)\) (each node is processed once).
- **Total**: \(O(n)\).

### Space Complexity:
- **Dictionary Storage**: \(O(n)\).
- **Recursion Stack**: \(O(h)\), where \(h\) is the height of the tree.
- **Total**: \(O(n)\) for balanced trees or \(O(n + h)\) for unbalanced trees.

### Dry Run 

Here’s a detailed dry run of the algorithm using the example:

Input:
preorder = [3, 9, 20, 15, 7]
inorder = [9, 3, 15, 20, 7]

#### Explanation:
- Step 1: Build a Dictionary of Inorder Indices
We first create a dictionary that maps each value to its index in the inorder array:
inorderMap = {9: 0, 3: 1, 15: 2, 20: 3, 7: 4}
This allows us to quickly locate the index of any value in the inorder array.

- Step 2: Start Building the Tree
We start by calling the BuildTree function with the given preorder and inorder arrays:
BuildTree(preorder, inorder)
This will call the helper function BuildTreeHelper(preorder, inorderMap, 0, 4) where 0 is the start index and 4 is the end index of the inorder array.

- Step 3: BuildTreeHelper Recursion Process
Recursive Call 1:
startIndex = 0, endIndex = 4
The root of the tree is the first element in the preorder array, which is 3. We create a root node with value 3.
root = 3

We find the index of 3 in the inorder array using inorderMap:
inIndex = inorderMap[3] = 1
Now, the left subtree will be built from the range inorder[0, 0] and the right subtree will be built from inorder[2, 4].
Recursive Call 2: Left Subtree of 3
startIndex = 0, endIndex = 0
The next element in the preorder array is 9. We create a left child node with value 9.
root.left = 9

We find the index of 9 in the inorder array:
inIndex = inorderMap[9] = 0
Now, we attempt to build the left and right subtrees for 9. Since startIndex > endIndex for both left and right, we return null for both.

root.left.left = null
root.left.right = null
Recursive Call 3: Right Subtree of 3
startIndex = 2, endIndex = 4

The next element in the preorder array is 20. We create a right child node with value 20.

root.right = 20
We find the index of 20 in the inorder array:

inIndex = inorderMap[20] = 3
Now, the left subtree will be built from inorder[2, 2] and the right subtree from inorder[4, 4].

Recursive Call 4: Left Subtree of 20
startIndex = 2, endIndex = 2

The next element in the preorder array is 15. We create a left child node with value 15.

root.left = 15
We find the index of 15 in the inorder array:

inIndex = inorderMap[15] = 2
Since startIndex > endIndex for both left and right, we return null for both.

root.left.left = null
root.left.right = null
Recursive Call 5: Right Subtree of 20
startIndex = 4, endIndex = 4

The next element in the preorder array is 7. We create a right child node with value 7.

root.right = 7
We find the index of 7 in the inorder array:

inIndex = inorderMap[7] = 4
Since startIndex > endIndex for both left and right, we return null for both.

root.right.left = null
root.right.right = null
Final Tree Structure
At the end of all recursive calls, the tree is fully constructed:

Summary of Recursive Calls:
Call 1: Root node is 3. Left subtree is rooted at 9, right subtree is rooted at 20.
Call 2: Root node is 9. Both left and right subtrees are null.
Call 3: Root node is 20. Left subtree is rooted at 15, right subtree is rooted at 7.
Call 4: Root node is 15. Both left and right subtrees are null.
Call 5: Root node is 7. Both left and right subtrees are null.
This is the dry run of the algorithm, showing how the binary tree is reconstructed from the given preorder and inorder arrays.
