class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i;
        int n=nums.size();
        int sum=(n*(n+1))/2;
        int sum1=0;
        for(i=0;i<n;i++)
        {
           sum1=sum1+nums[i];
        }
      int miss=sum-sum1;
      return miss;
    }
};