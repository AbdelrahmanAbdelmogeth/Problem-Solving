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
    public bool IsBalanced(TreeNode root) {
        if (root == null) return true;
        
        int leftHeight = GetHeight(root.left);
        int rightHeight = GetHeight(root.right);
        
        int absHeight = Math.Abs(leftHeight - rightHeight);
        if (absHeight <= 1 && IsBalanced(root.left) && IsBalanced(root.right)) {
            return true;
        }
        return false;    
    }
    
    private int GetHeight(TreeNode node) {
        if (node == null) return 0;
        
        int leftHeight = GetHeight(node.left);
        int rightHeight = GetHeight(node.right);
        
        return Math.Max(leftHeight, rightHeight) + 1;
    }
}
