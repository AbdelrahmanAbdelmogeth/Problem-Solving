/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        List<TreeNode> pNodePath = new List<TreeNode>();
        List<TreeNode> qNodePath = new List<TreeNode>();
        
        if(FindPath(root, p, pNodePath) == false || FindPath(root, q, qNodePath) == false)
            return null;
        
        int i;
        for (i = 0; i < pNodePath.Count && i < qNodePath.Count; i++) {
            if (pNodePath[i] != qNodePath[i])
                break;
        }
        
        return pNodePath[i - 1]; // Return the last common ancestor
    }
    
    private bool FindPath(TreeNode root, TreeNode node, List<TreeNode> NodePath) {
        if (root == null) return false; // Base Case – Check if the current node is null
        
        NodePath.Add(root); // Add the current node (root) to the NodePath list. Assume the current node is a part of the node's path
        
        if (root.val == node.val) return true; // Check if the current node is the target node retrun true indicating a success found

        if (node.val < root.val) {
            // If the target node's value is smaller, search the left subtree
            if (FindPath(root.left, node, NodePath))
                return true;
        } else {
            // If the target node's value is greater, search the right subtree
            if (FindPath(root.right, node, NodePath))
                return true;
        }

        NodePath.RemoveAt(NodePath.Count - 1); // Backtracking – Remove the current node if it's not part of the path since neither subtree found the target node, the current node is not on the path to the target node.
        return false; // Return false to indicate failure and allow the previous recursive call to continue its search.
    }
    

}