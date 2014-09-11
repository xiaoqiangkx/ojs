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
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;
        
        while (slow && fast) {
            slow = slow->next;
            if (fast->next == NULL) {
                return NULL;
            }
            
            fast = fast->next->next;
            if (slow == fast) {
                slow = &dummy;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                
                return slow;
            }
        }
        
        return NULL;
    }
};
