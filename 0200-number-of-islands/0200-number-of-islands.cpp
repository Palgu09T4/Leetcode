class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& grid)
    {
        vis[row][col]=1;
       
        int n = grid.size();
    int m = grid[0].size();
     
         int delrow[] = {-1, 0, +1, 0}; 
      int delcol[] = {0, -1, 0, +1}; 
            
            for(int i = 0; i < 4; i++)
                {
                   int nrow=row+delrow[i];
                    int ncol=col+delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    
                    dfs(nrow,ncol,vis,grid);
               }
            }
        
            }
            
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!vis[row][col] && grid[row][col]=='1')
                {
                    cnt++;
                    dfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};