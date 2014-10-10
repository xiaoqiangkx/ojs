#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
       ListNode dummy(-1);
       ListNode *tail = &dummy;
       
       int carry = 0;
       while (!l1 && !l2) {
           int sum = l1->val + l2->val + carry;
           carry = sum / 10;
           ListNode *new_node = new ListNode(sum % 10);
           new_node->next = tail->next;
           tail->next = new_node;
           tail = tail->next;
           
           l1 = l1->next;
           l2 = l2->next;
       }
       
       ListNode *p = (l1 != NULL ? l1 : l2);
       while (p != NULL) {
           int sum = p->val + carry;
           carry = sum / 10;
           ListNode *new_node = new ListNode(sum % 10);
           new_node->next = tail->next;
           tail->next = new_node;
           tail = tail->next;
           
           p = p->next;
       }
       
       if (carry != 0) {
           ListNode *new_node = new ListNode(carry);
           new_node->next = tail->next;
           tail->next = new_node;
           tail = tail->next;
       }
       
       return dummy.next;
    }
};

int main() {
	Solution s;
	ListNode *l1 = new ListNode(0);
	ListNode *l2 = new ListNode(1);
	s.addTwoNumbers(l1, l2);
	return 0;
} 
