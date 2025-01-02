/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parentchild(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mpp)
    {
        if(root==NULL)
        {
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node->left)
            {
                mpp[node->left]=node;
               q.push(node->left);
            }
            if(node->right)
            {
                mpp[node->right]=node;
                q.push(node->right);
            }
        }

        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        unordered_map<TreeNode*,bool>visited;
        vector<int>ans;
        parentchild(root,mpp);
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int level=0;
        while(!q.empty())
        {
            int n=q.size();
            
              if(level==k)break;
              level++;
            for(int i=0;i<n;i++)
            {
            
              TreeNode* node=q.front();
               q.pop();
            
            

            if(node->left && !visited[node->left])
            {
                    q.push(node->left);
                    visited[node->left]=true;
            }
            if(node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right]=true;
            }
            if(mpp[node] && !visited[mpp[node]])
            {
                q.push(mpp[node]);
                visited[mpp[node]]=true;
            }
    
        }
        

    }
    while(!q.empty())
    {
        TreeNode* node=q.front();
        q.pop();
        ans.push_back(node->val);
    }
    return ans;
    }
};