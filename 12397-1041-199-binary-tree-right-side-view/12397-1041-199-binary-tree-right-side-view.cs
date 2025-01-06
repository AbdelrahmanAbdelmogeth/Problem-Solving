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
    public IList<int> RightSideView(TreeNode root) {
        // at first we need to create the list that we want to return
        IList<int> result = new List<int>();
        if (root == null) // check if the tree is empty
            return result;

        // The queue is essential part of level order traversing that stores
        // the nodes of the current level
        Queue<TreeNode> queue = new Queue<TreeNode>(); 

        // starting from the root push the first level to the queue
        queue.Enqueue(root);
        while(queue.Count != 0){
            int levelSize = queue.Count; // Number of nodes at the current level
            //loop through the nodes in the current level and store the right-most node in the result list
            for(int i=0; i<levelSize; i++){
                TreeNode node = queue.Dequeue();
                if(i == levelSize - 1)
                    result.Add(node.val);
                
                // store the next level nodes by pushing the left and right children of the current node if they exist to the queue
                if(node.left != null)
                    queue.Enqueue(node.left);
                if(node.right != null)
                    queue.Enqueue(node.right);    
            }
        }
        return result;
    }
}