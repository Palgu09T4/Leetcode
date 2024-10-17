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
  void inorder(TreeNode* root,int k,int &cnt,int &kthsmall)
  {
    
    TreeNode* node=root;
    if(node==NULL)
    {
        return;
    }
    inorder(node->left,k,cnt,kthsmall);
    cnt++;
    if(cnt==k)
    {
        kthsmall=node->val;
        return;
    }
    inorder(node->right,k,cnt,kthsmall);
    

  }
    int kthSmallest(TreeNode* root, int k) {
        int kthsmall,cnt=0;
        inorder(root,k,cnt,kthsmall);
        return kthsmall;
    }
};