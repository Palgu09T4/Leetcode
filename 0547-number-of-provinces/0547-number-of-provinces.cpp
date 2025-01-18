class Solution {
public:
 void dfs(int node, vector<vector<int>>&isConnected, vector<bool>&vis) {
        // mark the more as visited
        vis[node] = true; 
        for(int i=0;i<isConnected.size();i++)
        {
            if(isConnected[node][i] && !vis[i]) {
                dfs(i,isConnected, vis); 
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(); 
       vector<bool>vis(n); 
        int cnt = 0; 
        for(int i = 0;i<n;i++) {
            // if the node is not visited
            if(!vis[i]) {
                // counter to count the number of provinces 
                cnt++;
               dfs(i, isConnected, vis); 
            }
        }
        return cnt; 
        
    
    }
};