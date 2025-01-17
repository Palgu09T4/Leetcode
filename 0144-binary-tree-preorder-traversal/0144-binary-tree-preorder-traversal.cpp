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
void preorder(TreeNode* root,vector<int>&arr)
{

  if(root == NULL)
    {
        return;
     }
  arr.push_back(root->val);
preorder(root->left,arr);
 preorder(root->right,arr);
 
}
    vector<int> preorderTraversal(TreeNode* root) {
     
      vector<int>arr;
        TreeNode* cur=root;
        while(cur)
        {
        if(cur->left==NULL)
        {
            arr.push_back(cur->val);
            cur=cur->right;
        }
        else
        {
            
            TreeNode* prev=cur->left;
            while(prev->right && prev->right!=cur)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right=cur;
                arr.push_back(cur->val);
                cur=cur->left;
            }
            else
            {
                prev->right=NULL;
                cur=cur->right;
            }
        }
        }
        
return arr;
        }
};