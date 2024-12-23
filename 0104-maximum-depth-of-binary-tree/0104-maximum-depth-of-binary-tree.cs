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
    private int maxDepth = 0;
    
    public int MaxDepth(TreeNode root) {
        if(root == null)
            return 0;
        Traverse(root, 1);
        return maxDepth;  
    }
    
    private void Traverse(TreeNode node, int depth){
        if(node == null)
            return;
        maxDepth = Math.Max(maxDepth, depth);
        
        this.Traverse(node.left, depth+1);
        this.Traverse(node.right, depth+1);
    }
}