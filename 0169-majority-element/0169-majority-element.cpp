class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int i;
	int cnt=0;
	int n=nums.size();
	int el;
	for(i=0;i<n;i++)
	{
		if(cnt==0)
		{
			cnt=1;
			el=nums[i];
		}
		else if(nums[i]==el)
		{
			cnt++;
		}
		else{
			cnt--;
		}
	}
   return el;
    }
};