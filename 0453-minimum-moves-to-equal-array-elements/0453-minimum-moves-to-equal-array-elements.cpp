class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=INT_MAX;
        int s=0;
       for(int i=0;i<nums.size();i++)
       {
        mini=min(mini,nums[i]);
       }  
       for(int i=0;i<nums.size();i++)
       {
         s+=(nums[i]-mini);
       }
       return s;
    }
};