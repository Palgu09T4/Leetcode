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
        int carry=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;
        while(l1!=NULL || l2!=NULL)
        {
            int sum=carry;
            if(l1)
            {
                sum=sum+l1->val;
            }
            if(l2)
            {
                sum=sum+l2->val;
            }
            ListNode* n=new ListNode(sum%10);
            carry=sum/10;
            cur->next=n;
            cur=cur->next;
            if(l1)
            {
                l1=l1->next;
            }
            if(l2)
            {
                l2=l2->next;
            }
        }
        if(carry)
        {
             ListNode* n=new ListNode(carry);
             cur->next=n;
        }
        return dummy->next;
    }
};