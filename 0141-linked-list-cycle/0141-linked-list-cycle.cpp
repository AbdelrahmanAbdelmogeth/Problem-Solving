#define FLOYED_CYCLE_DETECTION_ALGORITHM 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        #if FLOYED_CYCLE_DETECTION_ALGORITHM == 0
        unordered_set<ListNode*> pointer_add;
        int count = 0;
        for(ListNode* curr=head; curr!=nullptr; curr=curr->next, count++){
            if(pointer_add.find(curr) != pointer_add.end())
                return true;
            pointer_add.insert(curr);
        }
        return false;
        #endif
        
        #if FLOYED_CYCLE_DETECTION_ALGORITHM == 1
        ListNode* slow_ptr = head; ListNode* fast_ptr = head;
        while(slow_ptr != nullptr && fast_ptr != nullptr && fast_ptr->next != nullptr){
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
            if(slow_ptr == fast_ptr)
                return true;
        }
        return false;
        #endif
    }
};