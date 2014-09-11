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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;
        
        int cnt = 0;
        while (cnt < n) {
            fast = fast->next;
            ++cnt;
        }
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return dummy.next;
    }
};
