class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxl=0,maxr=0;
        int res=0;
        int l=0,r=n-1;
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>=maxl)
                {
                    maxl=height[l];
                }
                else
                {
                    res+=maxl-height[l];
                }
                l++;
            }
            else
            {
                if(height[r]>=maxr)
                {
                    maxr=height[r];
                }
                else
                {
                    res+=maxr-height[r];
                }
                r--;
            }
        }
        return res;
    }
};