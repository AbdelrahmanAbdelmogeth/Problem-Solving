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
    static ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *prev_ptr = nullptr;
        ListNode *curr_ptr = head;
        ListNode *temp = head;
        
        while(curr_ptr->next != nullptr){
            temp = curr_ptr->next;
            curr_ptr->next = prev_ptr;
            prev_ptr = curr_ptr;
            curr_ptr = temp;
        }
        curr_ptr->next = prev_ptr;
        return curr_ptr;
    }
    
    
    void reorderList(ListNode* head) {
        ListNode *slow_ptr = head;
        ListNode *fast_ptr = head;
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            // Move the fast pointer by two nodes
            fast_ptr = fast_ptr->next->next;
            // Move the slow pointer by one node
            slow_ptr = slow_ptr->next;
        }
        
        ListNode* second_half_ptr = slow_ptr->next;
        ListNode* rev_list = reverseList(second_half_ptr);
        slow_ptr->next = nullptr;
       
        /*
        //reverse is done perfectly
        ListNode *first_half = head;
        while(first_half != nullptr){
            cout<<first_half->val;
            first_half = first_half->next;
        }
        cout<<endl;
        //reverse is done perfectly
        ListNode *second_half = rev_list;
        while(second_half != nullptr){
            cout<<second_half->val;
            second_half = second_half->next;
        }
        */
        
        ListNode *curr = head;
        while(rev_list != nullptr){
            ListNode *curr_next = curr->next;
            ListNode* rev_list_next = rev_list->next;
            curr->next = rev_list;
            rev_list->next = curr_next;
            curr = curr_next;
            rev_list = rev_list_next;
        }
        
    }
};