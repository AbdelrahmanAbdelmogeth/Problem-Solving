<h2> 12397 1041
199. Binary Tree Right Side View</h2><hr><div><p>Given the <code>root</code> of a binary tree, imagine yourself standing on the <strong>right side</strong> of it, return <em>the values of the nodes you can see ordered from top to bottom</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [1,2,3,null,5,null,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,3,4]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/11/24/tmpd5jn43fs-1.png" style="width: 400px; height: 207px;"></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [1,2,3,4,null,null,null,5]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,3,4,5]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/11/24/tmpkpe40xeh-1.png" style="width: 400px; height: 214px;"></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [1,null,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,3]</span></p>
</div>

<p><strong class="example">Example 4:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = []</span></p>

<p><strong>Output:</strong> <span class="example-io">[]</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 100]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>
</div>

# 🌳 **Binary Tree Right Side View**

## 📚 **Problem Description**  
Given the **root** of a binary tree, imagine yourself standing on the **right side** of it. Return the **values of the nodes you can see** ordered from **top to bottom**.

---

## 🛠️ **Approach**

We use a **Breadth-First Search (BFS)** strategy, performing a **level-order traversal** of the binary tree.

### Key Steps:
1. **Level-Order Traversal:**  
   - Traverse the tree level by level using a **queue**.  

2. **Rightmost Node Selection:**  
   - At each level, add the **last node's value** (rightmost node) to the result list since that's the only node we can see when looking at the tree from the right.  

3. **Child Nodes:**  
   - Add the **left** and **right** child nodes of each current node to the queue for the next level.

---

## 🚀 **Algorithm**
1. Check if the tree is **empty**. If yes, return an **empty list**.  
2. Initialize a **queue** and add the **root node**.  
3. While the queue is **not empty**:  
   - Determine the **number of nodes** at the current level.  
   - Iterate through these nodes:  
     - Add the **rightmost node** of the level to the result list.  
     - Enqueue the **left** and **right** children if they exist.  
4. Return the **result list**.

---

## 📊 Complexity Analysis
### Time Complexity: 𝑂(𝑛)
- Each node is visited exactly once, where n is the number of nodes in the tree.

### Space Complexity: 𝑂(𝑑)
- At most, the queue stores up to d nodes, where d is the maximum width of the tree.

