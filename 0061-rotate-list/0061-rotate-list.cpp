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
    ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL)
    {
        return NULL;
    }
    ListNode* temp=head;
    int cnt=1;
    while(temp->next!=NULL)
    { 
        cnt++;
        temp=temp->next;
    }
    k=k%cnt;
    int end=cnt-k;
    temp->next=head;
    while(temp!=NULL && end>0)
    {
        end--;
        temp=temp->next;
    }
    head=temp->next;
    temp->next=NULL;
    return head;
    }
};