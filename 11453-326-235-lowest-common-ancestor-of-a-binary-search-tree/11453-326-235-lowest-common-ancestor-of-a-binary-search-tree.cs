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
    
    private bool FindPath(TreeNode root, TreeNode node, List<TreeNode> NodePath){
        if(root == null) return false;
        NodePath.Add(root);
        if(root.val == node.val) return true;
        if(FindPath(root.left, node, NodePath) || FindPath(root.right, node, NodePath))
            return true;
        NodePath.RemoveAt(NodePath.Count - 1);
        return false;
    }
}