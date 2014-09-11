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
    ListNode *reverseKGroup(ListNode *head, int k) {
        int n = count(head);
        if (n == 0 || k == 0) {
            return head;
        }
        
        int group = n / k;
        int cnt = 0;
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        ListNode *p = head;
        while (cnt < group) {
            reverse(p, k, tail);
            ++cnt;
        }
        
        tail->next = p;
        return dummy.next;
    }
    
    int count(ListNode *p) {
        int cnt = 0;
        while (p) {
            ++cnt;
            p = p->next;
        }
        
        return cnt;
    }
    
    void reverse(ListNode *(&p), int k, ListNode *(&tail)) {
        ListNode dummy(-1);
        ListNode *tmpTail = &dummy;
        
        int cnt = 0;
        while (cnt < k) {
            ListNode *tmp = p;
            p = p->next;
            ++cnt;
            
            if (dummy.next == NULL) {
                tmpTail = tmp;
            }
            
            tmp->next = dummy.next;
            dummy.next = tmp;
        }
        
        tail->next = dummy.next;
        tail = tmpTail;
    }
};
