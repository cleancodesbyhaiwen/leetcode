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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* dummy = new ListNode();
        
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        
        for(int i = 0;i < left - 1;i++){
            pre = pre->next;
            cur = cur->next;
        }
        for(int i = 0;i < right - left;i++){
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return dummy->next;
    }
};