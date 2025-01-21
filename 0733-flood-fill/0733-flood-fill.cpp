class Solution {
public:
void dfs(int row,int col,vector<vector<int>>&ans,int color,int ini)
{
    ans[row][col]=color;
    int n=ans.size();
    int m=ans[0].size();
    int drow[4]={0,-1,1,0};
    int dcol[4]={-1,0,0,1};
    for(int i=0;i<4;i++)
    {
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==ini)
        {
            dfs(nrow,ncol,ans,color,ini);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int ini=image[sr][sc];
        if(ini !=color)
        {
        dfs(sr,sc,ans,color,ini);
        }
        return ans;
    }
};