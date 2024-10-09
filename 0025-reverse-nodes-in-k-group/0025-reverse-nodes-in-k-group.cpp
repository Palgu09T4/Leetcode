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
 ListNode* kthnodefun(ListNode* temp,int k)
 {
    k-=1;
    while(temp!=NULL && k>0)
    {
        k--;
        temp=temp->next;
    }
    return temp;
 }
 ListNode* reverse(ListNode* head)
 {
    ListNode* temp=head;
    ListNode* prev=NULL;
    while(temp!=NULL)
    {
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=temp=front;
    }
    return prev;
 }
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevlast=NULL;
        while(temp!=NULL)
        {
        ListNode* kthnode=kthnodefun(temp,k);
        if(kthnode==NULL)
        {
            if(prevlast)
            {
                prevlast->next=temp;
                break;
            }
        }
        ListNode* nextnode=kthnode->next;
        kthnode->next=NULL;
        reverse(temp);
        if(temp==head)
        {
            head=kthnode;

        }
        else
        {
            prevlast->next=kthnode;
        }
        prevlast=temp;
        temp=nextnode;
        }
        return head;
    }
};