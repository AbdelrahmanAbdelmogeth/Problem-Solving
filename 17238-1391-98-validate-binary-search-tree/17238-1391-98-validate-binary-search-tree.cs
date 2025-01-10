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
    public bool IsValidBST(TreeNode root) {
        return IsValidBSTPostOrderTraversal(root, long.MinValue, long.MaxValue);
    }

    /*
        For BST all nodes in the left subtree must be smaller that their parent
        and all nodes in the right subtree must be larger that their parent
        this is true for each level so any node to know wheather it's valid or not 
        must know the value of its parent 
    */
    private bool IsValidBSTPostOrderTraversal(TreeNode root, long min, long max){
        if(root == null) // base case true when there is no node
            return true;

        // keep traversing left and each child node in the left subtree
        // shouldn't exceed the node value so we give the current node.val
        // as max 
        if(!IsValidBSTPostOrderTraversal(root.left,min,root.val))
            return false;
        // then traversing right and each child node in the right subtree
        // shouldn't be smaller than the node value so we give the current node.val
        // as min     
        if(!IsValidBSTPostOrderTraversal(root.right,root.val,max))
            return false;
    
        // now check for the node's val range within the constraints derived from the parent node
        if(root.val <= min || root.val >= max)
            return false;

        return true;
    }
}