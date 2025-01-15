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
    int result = Int32.MinValue; // global variable to hold the result
    public int MaxPathSum(TreeNode root) {
        int res = MaxPathSumPostOrderHelper(root);
        return this.result;
    }

    public int MaxPathSumPostOrderHelper(TreeNode root){
        if(root == null) //base case return 0 if the node is null
            return 0;

        // ordinary postorder
        int leftMax = MaxPathSumPostOrderHelper(root.left); // traverse left subtree
        int rightMax = MaxPathSumPostOrderHelper(root.right); // traverse right subtree

        /*
            The next two lines are essential for that reason:
            This ensures that the contribution from the left/right subtree is non-negative. If leftMax/rightMax (the maximum path sum from the left/right subtree) is negative, adding it to the current node's value would decrease the overall path sum. By taking the maximum of leftMax and 0, you effectively "ignore" the left/right subtree's contribution if it is negative.
        */
        leftMax = Math.Max(leftMax, 0);
        rightMax = Math.Max(rightMax, 0);

        //update the result variable;
        this.result = Math.Max(this.result, (root.val + leftMax + rightMax));
        // return the max path that current node and its children can make to the parent 
        return root.val + Math.Max(leftMax, rightMax);        
    }
}
