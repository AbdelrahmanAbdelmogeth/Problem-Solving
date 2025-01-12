/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Solution {
    private int answer; // Stores the value of the k-th smallest element.
    private int count = 0; // Counter to track the current position during in-order traversal.

    /**
     * Finds the k-th smallest element in a binary search tree (BST).
     * @param root The root node of the BST.
     * @param k The k-th position to find (1-based index).
     * @return The value of the k-th smallest element in the BST.
     */
    public int KthSmallest(TreeNode root, int k) {
        KthSmallestInorderTraversal(root, k); // Perform in-order traversal to find the element.
        return answer;
    }

    /**
     * Helper method to perform in-order traversal of the BST.
     * @param root The current node in the traversal.
     * @param k The k-th position to find.
     */
    private void KthSmallestInorderTraversal(TreeNode root, int k) {
        if (root == null) // Base case: If the node is null, return.
            return;

        // Traverse the left subtree.
        KthSmallestInorderTraversal(root.left, k);

        // Increment the counter and check if the current node is the k-th smallest.
        count++;
        if (k == count) {
            answer = root.val; // Assign the value of the k-th smallest element.
            return; // Exit traversal early as we found the k-th element.
        }

        // Traverse the right subtree.
        KthSmallestInorderTraversal(root.right, k);
    }
}