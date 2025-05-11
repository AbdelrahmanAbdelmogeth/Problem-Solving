/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    /*
        Function to create a deep copy of a linked list with both next and random pointers.
        The algorithm uses a three-pass approach:
            1. Interleave cloned nodes with original nodes.
            2. Set random pointers of the cloned nodes.
            3. Separate the original and cloned nodes into two distinct lists.
    */
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 1. Interleave cloned nodes with the original list:
        //    Original: A -> B -> C
        //    Becomes:  A -> A' -> B -> B' -> C -> C'
        Node* curr = head;
        while (curr != NULL) {
            Node* new_node = new Node(curr->val);
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next;
        }

        // 2. Set the random pointers of the cloned nodes:
        //    If original node's random is R, then cloned node's random is R->next
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next; // move to the next original node
        }

        // 3. Separate the original and copied lists
        Node* cloned_head = head->next; // head of the copied list
        curr = head;
        Node* clone = curr->next;
        while (clone->next != NULL) {
            curr->next = curr->next->next;     // restore original list
            clone->next = clone->next->next;   // fix next of copied node

            curr = curr->next;
            clone = clone->next;
        }

        // Final step to terminate both lists properly
        curr->next = NULL;
        clone->next = NULL;

        return cloned_head;
    }
};
