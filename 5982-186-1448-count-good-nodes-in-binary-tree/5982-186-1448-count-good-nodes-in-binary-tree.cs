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
    private int NumberOfGoodNodes = 0; // holds the number of good node in the tree 

    public int GoodNodes(TreeNode root) {
        PreOrderTraversal(root, root.val); // The number of nodes in the binary tree is in the range [1, 10^5]. so starting with the value of the root as the max in the path and start a preorder traversal of the tree
        return NumberOfGoodNodes; // return the number of good nodes at the end
    }

     /*
    Inorder to solve this problem the node itself must decide wheather it's a good node or not, so to do this the node must know the maximum value of the nodes before it in the path. that's acheived by passing this value to the next node in the path.
 */
    public void PreOrderTraversal(TreeNode node, int maxElementInPath){
        if(node == null)
            return;
        if(maxElementInPath <= node.val) // here the node decides whether it's good or not if yes we increment NumberOfGoodNodes by one
            NumberOfGoodNodes++;

        int MaxSoFar = Math.Max(maxElementInPath, node.val); // decide the maximum value of the path
        PreOrderTraversal(node.left, MaxSoFar); // traverse the left side
        PreOrderTraversal(node.right, MaxSoFar); // traverse the right side
    }
}