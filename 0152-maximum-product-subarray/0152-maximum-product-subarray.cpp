class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=1,suff=1,res=nums[0],ans=nums[0];
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(pre==0)pre=1;
            if(suff==0)suff=1;
          pre*=nums[i];
          suff*=nums[n-i-1];
          
          res=max(res,max(pre,suff));
        }
        return res;
    }
};