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
    ListNode *detectCycle(ListNode *head) {
        
        // If there is only one or no element in the list, there is not a loop for sure
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(slow != NULL && fast != NULL)
        {
            slow = slow->next;
            
            // For fast pointer, we need if it is the last element
            // in the list. If it is, then there is no loop, return NULL
            if(fast->next == NULL)
            {
                return NULL;
            }
            fast = fast->next->next;
            
            if(slow == fast)
            {
                ListNode* temp1 = head;
                ListNode* temp2 = fast;
                while(temp1 != temp2)
                {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
                return temp1;
            }
        }
        
        return NULL;
        
    }
};