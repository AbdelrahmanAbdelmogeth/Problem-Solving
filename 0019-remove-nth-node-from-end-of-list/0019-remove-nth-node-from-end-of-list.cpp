#define DELAYED_POINTER_APPROACH  1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        #if DELAYED_POINTER_APPROACH == 0
        ListNode* curr = head;
        int no_of_nodes = 1;
        while(curr->next != nullptr){
            curr = curr->next;
            no_of_nodes++;
        }
            
        int nth_node_from_start = no_of_nodes - n;
        int counter = 1; curr = head;
        
        ListNode* to_delete;
        if(nth_node_from_start == 0){
            to_delete = head;
            head = head->next;
            delete to_delete;
            return head;
        }
        
        while(counter != nth_node_from_start){
            curr = curr->next;
            counter++;
        }
        to_delete = curr->next;
        curr->next = curr->next->next;
        delete to_delete;
        
        return head;
        #endif
        
        #if DELAYED_POINTER_APPROACH == 1
        
        ListNode* delayed = head;
        ListNode* curr = head;
        int i = 1; int j = 1;
        
        while(curr->next != nullptr){
            curr = curr->next; i++;
            if(i-j > n){
                delayed = delayed->next;
                j++;
            }
        }
        
        ListNode* to_delete;
        if(i-j < n){
            to_delete = head;
            head = head->next;
            delete to_delete;
            return head;
        }
        
        to_delete = delayed->next;
        delayed->next = delayed->next->next;
        delete to_delete;
        
        return head;
        #endif
        
        
    }
};