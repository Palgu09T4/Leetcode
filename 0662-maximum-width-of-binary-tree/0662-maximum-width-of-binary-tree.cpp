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
    int widthOfBinaryTree(TreeNode* root) {
        
        long long maxi=0;
        if(root==NULL)return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            long long min=q.front().second;
            long long first,last;
            for(int i=0;i<n;i++)
            {
                long long curin=q.front().second-min;
                TreeNode* node=q.front().first;
                q.pop();
                 if(i==0)first=curin;
                if(i==n-1)last=curin;
                if(node->left)q.push({node->left,curin*2+1});
                if(node->right)q.push({node->right,curin*2+2});
                
            }
           
            maxi=max(maxi,last-first+1);
            }
        static_cast<int>(maxi);
        return maxi;
    }
};