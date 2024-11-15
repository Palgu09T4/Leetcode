class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,maxi=0;
        int mini=INT_MAX;
        int n=prices.size();
        for(i=0;i<n;i++)
        {
            mini=min(mini,prices[i]);
            maxi=max(maxi,prices[i]-mini);
        }
        return maxi;
    }
};