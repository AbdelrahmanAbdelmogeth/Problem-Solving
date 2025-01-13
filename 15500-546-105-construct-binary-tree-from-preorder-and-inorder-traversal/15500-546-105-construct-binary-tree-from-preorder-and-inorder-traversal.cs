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

// naive approach Time Comlexity: O(n^2)
// public class Solution {
//     // Index pointer to track the current root in the preorder array
//     int breIndex = 0;

//     /**
//      * Builds a binary tree from the given preorder and inorder traversal arrays.
//      * 
//      * @param preorder An array representing the preorder traversal of the tree.
//      * @param inorder An array representing the inorder traversal of the tree.
//      * @return The root of the reconstructed binary tree.
//      */
//     public TreeNode BuildTree(int[] preorder, int[] inorder) {
//         return BuildTreeHelper(preorder, inorder, 0, inorder.Length - 1);
//     }

//     /**
//      * Helper function to recursively construct the binary tree.
//      * 
//      * @param preorder The preorder traversal array.
//      * @param inorder The inorder traversal array.
//      * @param startIndex The starting index of the current subtree in the inorder array.
//      * @param endIndex The ending index of the current subtree in the inorder array.
//      * @return The root node of the constructed subtree.
//      */
//     private TreeNode BuildTreeHelper(int[] preorder, int[] inorder, int startIndex, int endIndex) {
//         // Base case: If start index exceeds end index, return null (no subtree exists)
//         if (startIndex > endIndex) return null;

//         // Create the root node using the current value in the preorder array
//         TreeNode root = new TreeNode(preorder[breIndex++]);

//         // Find the index of the root value in the inorder array
//         int inIndex = 0;
//         for (int i = startIndex; i <= endIndex; i++) {
//             if (inorder[i] == root.val) {
//                 inIndex = i;
//                 break;
//             }
//         }

//         // Recursively construct the left subtree using the left partition of the inorder array
//         root.left = BuildTreeHelper(preorder, inorder, startIndex, inIndex - 1);

//         // Recursively construct the right subtree using the right partition of the inorder array
//         root.right = BuildTreeHelper(preorder, inorder, inIndex + 1, endIndex);

//         // Return the root node of the current subtree
//         return root;
//     }
// }



// Enhanced Code using dictionary Time Comlexity: O(n)
public class Solution {
    // Index pointer for the preorder traversal
    int breIndex = 0;

    /**
     * Builds a binary tree from the given preorder and inorder traversal arrays.
     * 
     * @param preorder An array representing the preorder traversal of the tree.
     * @param inorder An array representing the inorder traversal of the tree.
     * @return The root of the reconstructed binary tree.
     */
    public TreeNode BuildTree(int[] preorder, int[] inorder) {
        // Create a dictionary to store the index of each value in the inorder array
        Dictionary<int, int> inorderMap = new Dictionary<int, int>();
        for (int i = 0; i < inorder.Length; i++) {
            inorderMap[inorder[i]] = i;
        }

        return BuildTreeHelper(preorder, inorderMap, 0, inorder.Length - 1);
    }

    /**
     * Helper function to recursively construct the binary tree.
     * 
     * @param preorder The preorder traversal array.
     * @param inorderMap A dictionary mapping values to their indices in the inorder array.
     * @param startIndex The starting index of the current subtree in the inorder array.
     * @param endIndex The ending index of the current subtree in the inorder array.
     * @return The root node of the constructed subtree.
     */
    private TreeNode BuildTreeHelper(int[] preorder, Dictionary<int, int> inorderMap, int startIndex, int endIndex) {
        // Base case: If start index exceeds end index, return null (no subtree exists)
        if (startIndex > endIndex) return null;

        // Create the root node using the current value in the preorder array
        TreeNode root = new TreeNode(preorder[breIndex++]);

        // Get the index of the root value in the inorder array using the dictionary
        int inIndex = inorderMap[root.val];

        // Recursively construct the left subtree using the left partition of the inorder array
        root.left = BuildTreeHelper(preorder, inorderMap, startIndex, inIndex - 1);

        // Recursively construct the right subtree using the right partition of the inorder array
        root.right = BuildTreeHelper(preorder, inorderMap, inIndex + 1, endIndex);

        // Return the root node of the current subtree
        return root;
    }
}

