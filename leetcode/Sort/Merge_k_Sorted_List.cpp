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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<ListNode*> data(lists);
        vector<ListNode*> next_data;
        
        while (data.size() > 1) {
            while (!data.empty()) {
                if (data.size() == 1) {
                    next_data.push_back(data.back());
                    data.pop_back();
                    break;
                }
                
                ListNode *first = data.back();
                data.pop_back();
                ListNode *second = data.back();
                data.pop_back();
                
                ListNode *mergeNode = merge(first, second);
                next_data.push_back(mergeNode);
            }
            
            data.swap(next_data);
        }
        
        if (data.size() == 0) {
            return NULL; 
        } else {
            return data[0];
        }
    }
    
    ListNode *merge(ListNode *first, ListNode *second) {
        ListNode *p = first;
        ListNode *q = second;
        
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        
        while (p != NULL && q != NULL) {
            if (p->val < q->val) {
                tail->next = p;
                tail = p;
                p = p->next;
            } else {
                tail->next = q;
                tail = q;
                q = q->next;
            }
        }
        
        if (p != NULL) {
            tail->next = p;
        } else {
            tail->next = q;
        }
        
        return dummy.next;
    }
};
