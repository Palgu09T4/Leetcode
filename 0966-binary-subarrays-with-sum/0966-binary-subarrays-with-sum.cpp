class Solution {
public:
int count(vector<int>&nums,int goal)
{

         if(goal<0)return 0;
         int l=0,r=0;
          int sum=0;
          int cnt=0;
         while(r<nums.size())
         {
             sum+=nums[r];
             while(sum>goal)
             {
                sum-=nums[l];
                l=l+1;
             }
            cnt=cnt+(r-l+1);
             r=r+1; 
         }
         return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return count(nums,goal)-count(nums,goal-1);
        
    }
     
};