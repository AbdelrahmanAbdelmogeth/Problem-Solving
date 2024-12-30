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
    public bool IsSubtree(TreeNode root, TreeNode subRoot) {
        if (subRoot == null) return true; // An empty tree is always a subtree 
        if (root == null) return false; // Main tree is empty, but subRoot is not 
        if (IsSameTree(root, subRoot)) return true; // Check recursively for every node in the tree 
        return IsSubtree(root.left, subRoot) || IsSubtree(root.right, subRoot);
    }

    public bool IsSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true; // Both are null 
        if (p == null || q == null) return false; // One is null, the other is not if (p.val 
        if(p.val != q.val) return false; // values are not the same
        
        return IsSameTree(p.left, q.left) && IsSameTree(p.right, q.right);
    }
}