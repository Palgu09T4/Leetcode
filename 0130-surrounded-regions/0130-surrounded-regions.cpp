class Solution {
public:
void dfs1(int row,int col,vector<vector<char>>&board,vector<vector<int>>&vis,int n,int m)
{
    vis[row][col]=1;
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && board[nrow][ncol]=='O')
        {
            dfs1(nrow,ncol,board,vis,n,m);
        }
    }
}
 void solve(vector<vector<char>>& board){
    int n=board.size();
    int m=board[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && board[0][j]=='O')
            {
                
               dfs1(0,j,board,vis,n,m);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O')
            {
                 dfs1(n-1,j,board,vis,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && board[i][0]=='O')
            {
                
               dfs1(i,0,board,vis,n,m);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O')
            {
                 dfs1(i,m-1,board,vis,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                {
                    board[i][j]='X';
                }
            }
        }

    }
};