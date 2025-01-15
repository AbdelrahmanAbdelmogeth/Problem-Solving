<h2> 17166 754
124. Binary Tree Maximum Path Sum</h2><hr><div><p>A <strong>path</strong> in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence <strong>at most once</strong>. Note that the path does not need to pass through the root.</p>

<p>The <strong>path sum</strong> of a path is the sum of the node's values in the path.</p>

<p>Given the <code>root</code> of a binary tree, return <em>the maximum <strong>path sum</strong> of any <strong>non-empty</strong> path</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/13/exx1.jpg" style="width: 322px; height: 182px;">
<pre><strong>Input:</strong> root = [1,2,3]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The optimal path is 2 -&gt; 1 -&gt; 3 with a path sum of 2 + 1 + 3 = 6.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/13/exx2.jpg">
<pre><strong>Input:</strong> root = [-10,9,20,null,null,15,7]
<strong>Output:</strong> 42
<strong>Explanation:</strong> The optimal path is 15 -&gt; 20 -&gt; 7 with a path sum of 15 + 20 + 7 = 42.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 3 * 10<sup>4</sup>]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>
</div>

# Solution: Maximum Path Sum in a Binary Tree

This solution calculates the **maximum path sum** in a binary tree. The path can begin and end at any node, and it does not need to pass through the root.

## Explanation of the Approach

### 1. **Global Variable (`result`)**
- A global variable `result` is used to store the maximum path sum encountered during the traversal of the tree.
- It is initialized to `Int32.MinValue` to ensure any computed path sum will replace it.

### 2. **Post-order Traversal**
- The solution uses a **post-order traversal** (left → right → root) to explore the tree.
- This ensures that for each node, the maximum contributions from its left and right subtrees are computed before processing the node itself.

### 3. **Handling Negative Contributions**
- If a subtree contributes a negative path sum, it is better to exclude it, as it would decrease the overall path sum.
- To achieve this, the solution uses:
  ```csharp
  leftMax = Math.Max(leftMax, 0);
  rightMax = Math.Max(rightMax, 0);
  ```
   
### 4. **Updating the Global Maximum**
- For each node, the potential maximum path sum that includes the current node as the highest point (root of the path) is calculated as:
```csharp
root.val + leftMax + rightMax
```
This value is compared with the global result variable, and result is updated if this value is larger.

### 5. **Returning to the Parent**
After calculating the maximum path sum involving the current node, the function needs to return the maximum contribution this node can provide to its parent.
This is given by:
```csharp
root.val + Math.Max(leftMax, rightMax)
```
It includes the node's value and the greater of the left or right subtree's contribution.  

## Complexity Analysis
- Time Complexity: 
𝑂(𝑛) Each node is visited exactly once during the traversal.
- Space Complexity: 
𝑂(ℎ) The space required is proportional to the height of the tree, due to the recursion stack.
