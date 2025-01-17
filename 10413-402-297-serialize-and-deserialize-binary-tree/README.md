<h2> 10413 402
297. Serialize and Deserialize Binary Tree</h2><hr><div><p>Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.</p>

<p>Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.</p>

<p><strong>Clarification:</strong> The input/output format is the same as <a href="https://support.leetcode.com/hc/en-us/articles/32442719377939-How-to-create-test-cases-on-LeetCode#h_01J5EGREAW3NAEJ14XC07GRW1A" target="_blank">how LeetCode serializes a binary tree</a>. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/serdeser.jpg" style="width: 442px; height: 324px;">
<pre><strong>Input:</strong> root = [1,2,3,null,null,4,5]
<strong>Output:</strong> [1,2,3,null,null,4,5]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>
</div>

# Binary Tree Serialization and Deserialization Explanation

## Overview
Serialization and deserialization of a binary tree involve converting the tree structure into a string representation and reconstructing the tree from that string.

---

A Naive Solution would be storing inorder traversal and another traversal, maybe post or preorder, but we can do better by doing only one traversal. I will arbitrarily choose inorder (node -> left -> right) and store all node values, even the null ones. This ensures that both the structure (node connections) and the values of the tree are fully captured in the serialized string.

---

### Serialization
- **Purpose**: Convert the binary tree into a single string that represents its structure and values.
- **Approach**:
  - Use **in-order traversal** (visit node, left subtree, then right subtree).
  - Append the value of each node to a `StringBuilder` for efficiency.
  - Use `#` to represent null nodes.
  - Use `,` as a delimiter to separate node values.
- **Why StringBuilder**: Unlike normal strings in C#, `StringBuilder` supports efficient mutation, making it ideal for appending values during traversal.

---

### Deserialization
- **Purpose**: Reconstruct the binary tree from the serialized string.
- **Approach**:
  - Split the serialized string using `,` into an array or queue of values.
  - Use a **queue**:
    - A queue ensures sequential access to the nodes, matching the order in which they were serialized.
    - Eliminates the need to maintain an explicit index.
  - Recursively reconstruct the tree:
    - If the current value is `#`, return `null` (indicating no child).
    - Otherwise, create a new `TreeNode` with the value.
    - Recur for the left and right children.

---

### Why Use a Queue?
- The nodes are processed in the same order as they were serialized (in-order traversal).
- A queue simplifies managing the traversal order without needing explicit indexing.

---

### Key Points
1. **Null Nodes**:
   - Represented by `#` during serialization to capture tree structure.
   - Prevents ambiguity when deserializing.
   
2. **Efficiency**:
   - `StringBuilder` ensures efficient serialization with minimal memory allocation.
   - A queue eliminates unnecessary array indexing during deserialization.

3. **Traversal**:
   - In-order traversal ensures nodes are visited and serialized in a logical order, making deserialization straightforward.

4. **Base Cases**:
   - Serialization: Append `#` for null nodes.
   - Deserialization: Stop recursion when the queue is empty or when encountering `#`.

---

### Workflow
1. **Serialization**:
   - Start at the root.
   - Traverse the tree recursively using in-order traversal.
   - Build the string by appending values and `#` for null nodes.

2. **Deserialization**:
   - Split the serialized string into a queue.
   - Recursively reconstruct the tree, processing nodes in the order they appear.

---

### Advantages
- Compact representation of the binary tree.
- Easy to debug due to the clear mapping of serialized string to tree structure.
- Efficient in both time and space when processing large trees.

### Overall Complexity
- Time Complexity: O(n) for both serialization and deserialization.
- Space Complexity:
  - O(n) for storing the serialized string or input queue.
  - O(h) additional space for the recursion stack during traversal, where h is the height of the tree.
