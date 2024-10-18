/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void inorder(TreeNode* root,TreeNode* &prev,TreeNode* &first,TreeNode* &last)
{
    if(root==NULL)return;
    inorder(root->left,prev,first,last);
    if(prev!=NULL && root->val<prev->val)
    {
        if(first==NULL)
        {
            first=prev;
        }
        last=root;
    }
    prev=root;
    inorder(root->right,prev,first,last);
}
    void recoverTree(TreeNode* root) {
        TreeNode* prev=NULL;
        TreeNode* first=NULL;
        TreeNode* last=NULL;
        
        
        inorder(root,prev,first,last);
        swap(first->val,last->val);
    }
};