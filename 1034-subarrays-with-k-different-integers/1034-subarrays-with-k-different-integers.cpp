class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
     int ans= func(nums,k);
      int ans1=func(nums,k-1);
       return (ans-ans1);
}
int func(vector<int>&nums,int k)
{
    int cnt=0,l=0,r=0;
    map<int,int>mpp;
       while(r<nums.size())
       {
                mpp[nums[r]]++;
                while(mpp.size()>k){      
                  mpp[nums[l]]--;
                   if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                   l=l+1;
                }
               cnt=cnt+(r-l+1);
               r=r+1;
            }
    return cnt;
    }


    };