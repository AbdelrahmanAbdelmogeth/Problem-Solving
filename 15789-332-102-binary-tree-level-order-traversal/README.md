<h2> 15789 332
102. Binary Tree Level Order Traversal</h2><hr><div><p>Given the <code>root</code> of a binary tree, return <em>the level order traversal of its nodes' values</em>. (i.e., from left to right, level by level).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;">
<pre><strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> [[3],[9,20],[15,7]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> [[1]]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>
</div>

# **Binary Tree Level Order Traversal**

## 📚 **Problem Statement**

Given the `root` of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

---

## 🛠️ **Solution Explanation**

### **Approach: BFS Using a Queue (Level Order Traversal)**

1. **Initialize Data Structures:**
   - Use a `Queue` to store nodes level by level.
   - Use a `List<IList<int>>` to store values of nodes at each level.

2. **Handle Edge Case:**
   - If the `root` is `null`, return an empty list.

3. **Level-by-Level Traversal:**
   - Start by enqueueing the `root` node.
   - While the queue is not empty:
     - Determine the number of nodes at the current level (`levelSize`).
     - Process each node at this level:
       - Dequeue the node and add its value to the current level's list.
       - Enqueue its left and right children if they exist.
     - Add the current level's list to the result.

4. **Return the Result:**
   - Return the list of levels after processing all nodes.

---

## 📊 Complexity Analysis
### Time Complexity:
- O(n), where n is the number of nodes in the binary tree.
- Each node is enqueued and dequeued exactly once, and processing each node (adding to the result list) takes constant time.
### Space Complexity:
- O(n) in the worst case.
- The queue can hold up to n/2 nodes in the last level of a complete binary tree.
- Additionally, the result list will store all node values.

