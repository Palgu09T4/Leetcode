class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    /*int maxi=INT_MIN;
    int sum=0;
    int n=nums.size();
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]>0)
        {
            flag=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
         maxi=max(sum,maxi);
        if(sum<0 && flag==1)
        {
           sum=0;
        }
    }
    if(maxi<0 && flag==1)
    {
        return 0;
    }
return maxi;

    }*/
    int maxSum = INT_MIN;
        int currentSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
            
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        
        return maxSum;
    }
};