/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invertTreeLevelOrderTraversal(root);
        return root;
    }
    
    void invertTreeLevelOrderTraversal(TreeNode* root) {
        if (root == nullptr)
            return;

        // Create an empty queue for level order traversal
        std::queue<TreeNode*> q;

        // Enqueue Root
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            
            // Swap the left and right children
            std::swap(node->left, node->right);
            
            // Enqueue left child
            if (node->left != nullptr) {
                q.push(node->left);
            }

            // Enqueue right child
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }
};