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
    private int diameter = 0;
    
    public int DiameterOfBinaryTree(TreeNode root) {
        CalculateDepth(root);
        return diameter;
    }
    
    private int CalculateDepth(TreeNode node){
        if(node == null)
            return 0;
        
        int leftDepth = CalculateDepth(node.left);
        int rightDepth = CalculateDepth(node.right);
        
        // Update the diameter if the path through the current node is larger
        diameter = Math.Max(diameter, leftDepth + rightDepth);
        
        // Return the depth of the node
        return Math.Max(leftDepth, rightDepth) + 1;
    }
}
