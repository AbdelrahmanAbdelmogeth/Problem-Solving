/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    StringBuilder sb = new StringBuilder(""); // string builder is used because it supports mutations unlike normal C# string
    // Encodes a tree to a single string.
    public string serialize(TreeNode root) {
        InOrderSerializeHelper(root); // call the helper serialize method
        return sb.ToString(); // return the string by converting the sb 
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(string data) {
        if (string.IsNullOrEmpty(data)) return null; // if the string is empty no need for further calculations

        // Split the data into a queue why used a queue 
        // the nodes are in order if i used an array i must mentain the index of the element in order for the node to know the left and right children or even itself
        Queue<string> nodes = new Queue<string>(data.Split(','));
        return InOrderDeserializeHelper(nodes); // call the deserialize helper method
    }

    private void InOrderSerializeHelper(TreeNode root) {
        if(root == null){ // base case if the node is null
            sb.Append("#,"); // append # if the node is null
            return;
        }

        sb.Append(root.val.ToString()); // append the node val to the string
        sb.Append(","); // add , to be able to identify the node value because the range is -1000 <= Node.val <= 1000
        InOrderSerializeHelper(root.left); // recursively call for the left child (inorder traversal)
        InOrderSerializeHelper(root.right); // recursively call for the right child (inorder traversal)
    }

    // Decodes your encoded data to tree.
    private TreeNode InOrderDeserializeHelper(Queue<string> nodes) {
        if(nodes.Count == 0) // the base case if the queue is empty return null
            return null;

        string val = nodes.Dequeue(); // get the value by dequeuing from the queue
        if(val == "#") return null; // if the val = # that means it's null value and return it to the caller

        TreeNode node = new TreeNode(int.Parse(val)); // create a new node with the value dequeued and convert it to int
        node.left =  InOrderDeserializeHelper(nodes); // recursively call for the left subtree first because that's inorder queue and left always first
        node.right =  InOrderDeserializeHelper(nodes); // then recursively call for the right subtree

        return node; // return the node after constructing all its children   
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));