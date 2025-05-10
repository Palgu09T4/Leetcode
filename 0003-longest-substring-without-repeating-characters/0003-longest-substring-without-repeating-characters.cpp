class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256]={0};
        int right=0,left=0,maxlen=0;
        while(right<s.size())
        {
            while(hash[s[right]]>0)
            {
                hash[s[left]]--;
                left++;
            }
            hash[s[right]]++;
            maxlen=max(maxlen,right-left+1);

            right++;
        }
        return maxlen;
    }
};