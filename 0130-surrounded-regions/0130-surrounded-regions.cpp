class Solution {
public:
 void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>> &vis,int m,int n){
        vis[row][col]=1;
        
        int x_row[]={-1,0,1,0};
        int x_col[]={0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nrow=row+x_row[i];
            int ncol=col+x_col[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && board[nrow][ncol]=='O' )
            dfs(nrow,ncol,board,vis,m,n);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int j=0;j<n;j++){
            if(board[0][j]=='O')
                dfs(0,j,board,vis,m,n);
            if(board[m-1][j]=='O')
                dfs(m-1,j,board,vis,m,n);
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
                dfs(i,0,board,vis,m,n);
            if(board[i][n-1]=='O')
                dfs(i,n-1,board,vis,m,n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};