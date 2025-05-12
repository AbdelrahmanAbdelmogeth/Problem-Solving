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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy_node = new ListNode(INT_MIN);
        ListNode* curr_add = dummy_node;

        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0){
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            curr_add->next = new ListNode(sum % 10);
            curr_add = curr_add->next;

            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }

        ListNode* add_res_to_return = dummy_node->next;
        delete dummy_node;
        return add_res_to_return;
    }
};