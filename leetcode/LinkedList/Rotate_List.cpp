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
    ListNode *rotateRight(ListNode *head, int k) {
        int n = count(head);
        if (n == 0) {
            return head;
        }
        k = k % n;
        if (0 == k) {
            return head;
        }
        
        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode *fast = &dummy;
        ListNode *slow = &dummy;
        int cnt = 0;
        while (cnt < k) {
            fast = fast->next;
            ++cnt;
        }
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        dummy.next = slow->next;
        fast->next = head;
        slow->next = NULL;
        
        return dummy.next;
    }
    
    int count(ListNode *head) {
        ListNode *p = head;
        int cnt = 0;
        while (p != NULL) {
            p = p->next;
            cnt++;
        }
        
        return cnt;
    }
};
