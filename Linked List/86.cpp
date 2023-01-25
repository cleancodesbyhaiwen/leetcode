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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* greater_head = new ListNode();
        ListNode* less_head = new ListNode();
        ListNode* greater = greater_head;
        ListNode* less = less_head;
        
        while(head != NULL)
        {
            if(head->val < x)
            {
                less->next = head;
                less = less->next;
            }
            else{
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        
        less->next = greater_head->next;
        greater->next = NULL;
        return less_head->next;
        
    }
};