class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes=0,l=0,r=0;
          int maxlen=INT_MIN;
       while(r<nums.size())
       {
                if(nums[r]==0)zeroes++;
                if(zeroes>k){
                    if(nums[l]==0) 
                    {
                        zeroes--;
                    }     
                    l++;
                }
                if(zeroes<=k)
                {
                    int len=r-l+1;
                    maxlen=max(len,maxlen);
                }
                
               r=r+1;
            }
    return maxlen;
    }

    
};